// 2015-05-16T16:17+08:00
// Broker peering simulation (part 1)
// Prototypes the state flow

#include "czmq.h"

int main(int argc, char *argv[])
{
	// First argument is this broker's name
	// Other argument are our peer's names
	//
	if (argc < 2) {
		printf("syntax: peering1 me {you}...\n");
		return 0;
	}
	char *self = argv[1];
	printf("I: preparing broker at %s...\n", self);
	srandom((unsigned)time(NULL));

	zctx_t *ctx = zctx_new();

	// Bind state backend to endpoint
	void *statebe = zsocket_new(ctx, ZMQ_PUB);

	// According to zguide, we prefer IPC to TCP in this example.
	// However, since IPC doesn't work on windows currently, so we
	// will still use TCP on windows.
#if (defined (WIN32))
	zsocket_bind(statebe, "tcp://*:%s", self);
#else
	zsocket_bind(statebe, "ipc://%s-state.ipc", self);
#endif

	// Connect statefe to all peers
	void *statefe = zsocket_new(ctx, ZMQ_SUB);
	zsocket_set_subscribe(statefe, "");
	int argn;
	for (argn = 2; argn < argc; argn++) {
		char *peer = argv[argn];
		printf("I: connecting to state backend at '%s'\n", peer);

#if (defined (WIN32))
		zsocket_connect(statefe, "tcp://localhost:%s", peer);
#else
		zsocket_connect(statefe, "ipc://%s-state.ipc", peer);
#endif
	}
	// .split main loop
	// The main loop sends out status messages to peers, and collects
	// status messages back from peers. The zmq_poll timeout defines
	// our own heartbeat:

	while (true) {
		// Poll for activity, or 1 second timeout
		zmq_pollitem_t items[] = { { statefe, 0, ZMQ_POLLIN, 0 } };
		int rc = zmq_poll(items, 1, 1000 * ZMQ_POLL_MSEC);
		if (rc == -1)
			break; // Interrupted

		// Handle incoming status messages
		if (items[0].revents & ZMQ_POLLIN) {
			char *peer_name = zstr_recv(statefe);
			char *available = zstr_recv(statefe);
			printf("%s - %s workers free\n", peer_name, available);
			free(peer_name);
			free(available);
		} else {
			// Send random values for worker availability
			zstr_sendm(statebe, self);
			zstr_sendf(statebe, "%d", randof(10));
		}
	}
	zctx_destroy(&ctx);
	return EXIT_SUCCESS;
}