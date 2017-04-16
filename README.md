arduino-mock[![Build Status](https://travis-ci.org/ikeyasu/arduino-mock.svg?branch=master)](https://travis-ci.org/ikeyasu/arduino-mock)
============
[![Gitter chat](https://badges.gitter.im/gitterHQ/gitter.png)](https://gitter.im/ikeyasu/arduino-mock)

[![Gitter](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/ikeyasu/arduino-mock?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

A GMock stub library for a mock of Arduino libraries.

How it works
============

This is the mock library for Arduino sketch program.
To run unittest for this mock, please follow this
instruction.

    $ git clone https://github.com/ikeyasu/arduino-mock.git
    $ cd arduino-mock
    $ git submodule update --init --recursive
    $ cd test
    $ make test
    for t in arduino_unittest serial_unittest spark_unittest; do ./$t; done;
    Running main() from gmock_main.cc
    [==========] Running 2 tests from 2 test cases.
    [----------] Global test environment set-up.
    [----------] 1 test from digitalRead
    [ RUN      ] digitalRead.2
    [       OK ] digitalRead.2 (1 ms)
    [----------] 1 test from digitalRead (1 ms total)

    [----------] 1 test from delay
    [ RUN      ] delay.normal
    [       OK ] delay.normal (0 ms)
    [----------] 1 test from delay (0 ms total)

    [----------] Global test environment tear-down
    [==========] 2 tests from 2 test cases ran. (1 ms total)
    [  PASSED  ] 2 tests.
    Running main() from gmock_main.cc
    [==========] Running 1 test from 1 test case.
    [----------] Global test environment set-up.
    [----------] 1 test from loop
    [ RUN      ] loop.pushed
    [       OK ] loop.pushed (1 ms)
    [----------] 1 test from loop (1 ms total)

    [----------] Global test environment tear-down
    [==========] 1 test from 1 test case ran. (1 ms total)
    [  PASSED  ] 1 test.
    Running main() from gmock_main.cc
    [==========] Running 1 test from 1 test case.
    [----------] Global test environment set-up.
    [----------] 1 test from publish
    [ RUN      ] publish.normal
    [       OK ] publish.normal (1 ms)
    [----------] 1 test from publish (1 ms total)

    [----------] Global test environment tear-down
    [==========] 1 test from 1 test case ran. (1 ms total)
    [  PASSED  ] 1 test.

Sample and how to install to your app
====================================

Please refer to
https://github.com/ikeyasu/arduino-gmock-sample

You need to copy "make/Makefile" to your app's dir
and modify it.

Contribution
============

Please send a pull-request.
You need to run code formatter before commiting.

Install formatter
-----------------

You need [astyle](http://astyle.sourceforge.net) 2.03.

Unbutun 14.04 LTS:

    $ sudo apt-get install astyle=2.03-1

Mac (Homebrew):

    $ brew tap ikeyasu/myversions
    $ brew install astyle203

Windows:
Please download from [here](http://sourceforge.net/projects/astyle/files/astyle/astyle%202.03/).

How to run formatter
--------------------

    $ ./script/codeformatter.sh
