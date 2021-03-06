[Amalgamation](https://github.com/EQ4/JUCEAmalgam#whats-an-amalgamation)
>## What's an amalgamation?
>
>An amalgamation is simply a collection of header and source files that have been concatenated together to form one or more very large files. In this form, they are easy to add to your existing project as source files (rather than linking as a library). They are also easier to redistribute if you are making an open source application and don't want to have any external dependencies.
>
>## Example:
>* [sqlite-amalgamation-3230100.zip](http://sqlite.org/2018/sqlite-amalgamation-3230100.zip)
>* [JuceAmalgam](https://github.com/vinniefalco/DSPFilters/tree/master/shared/JuceAmalgam)
>
>## Tools:
>* [Amalgamate](https://github.com/vinniefalco/Amalgamate)
>* [amalgamate.py](https://github.com/edlund/amalgamate) - [nlohmann/json](https://github.com/nlohmann/json/tree/develop/third_party/amalgamate) uses this tool to create a single header only library.
>* [amalgamate](https://gitlab.com/DerManu/QCustomPlot/blob/master/amalgamate)
>* [stitch.py](https://github.com/catchorg/Clara/blob/master/scripts/stitch.py) - [Clara](https://github.com/catchorg/Clara) uses this Python script to generate a single header library.
>* [cnl/src/single_header](https://github.com/johnmcfarlane/cnl/blob/develop/src/single_header/CMakeLists.txt)
>
>## References:
>[mio #23](https://github.com/mandreyel/mio/issues/23)
