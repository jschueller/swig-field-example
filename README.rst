swig field example
==================

regression test for https://github.com/swig/swig/commit/4b4e0180f42e992de6ff458477b70e4ec63ecb49 (https://github.com/swig/swig/pull/1279)

Usage
-----

    git clone https://github.com/jschueller/swig-field-example.git
    cd swig-field-example
    mkdir build && cd build
    cmake -DPYTHON_EXECUTABLE=/usr/bin/python3 -DCMAKE_INSTALL_PREFIX=$PWD/install ..
    PYTHONPATH=$PWD/install/lib/python3.6/site-packages python3 ../test-fieldfunction.py







