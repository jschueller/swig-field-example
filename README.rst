swig field example
==================

regression test for https://github.com/swig/swig/commit/4b4e0180f42e992de6ff458477b70e4ec63ecb49 (https://github.com/swig/swig/pull/1279)

Usage
-----

::

    git clone https://github.com/jschueller/swig-field-example.git
    cd swig-field-example
    mkdir build && cd build
    cmake -DSWIG_EXECUTABLE=/usr/bin/swig -DPYTHON_EXECUTABLE=/usr/bin/python3 -DCMAKE_INSTALL_PREFIX=$PWD/install ..
    PYTHONPATH=$PWD/install/lib/python3.6/site-packages python3 ../test-fieldfunction.py


Notes
-----

Using swig master you will see the following segfault (SwigThis returns 0 as the module is destroyed too early)::

    #0  0x00000000004c8e96 in PyObject_GetAttr ()
    #1  0x00007ffff666eeb2 in SWIG_Python_GetSwigThis (pyobj=<optimized out>) at /tmp/swig-field-example/build/swig_runtime.hxx:2022
    #2  0x00007ffff666ef60 in SWIG_Python_ConvertPtrAndOwn (obj=obj@entry=0x7ffff687aeb8, ptr=ptr@entry=0x7fffffffd250, ty=0x7ffff6871500 <_swigt__p_OT__Mesh>, own=0x0, flags=0) at /tmp/swig-field-example/build/swig_runtime.hxx:2072
    #3  0x00007ffff666f273 in OT::PythonFieldFunction::PythonFieldFunction (this=0xa91360, pyCallable=<optimized out>) at /tmp/swig-field-example/PythonFieldFunction.cxx:19
    #4  0x00007ffff666e6c3 in new_OT_FieldFunction__SWIG_3 (pyObj=0x7ffff687ae80) at /tmp/swig-field-example/build/openturnsPYTHON_wrap.cxx:2804
    #5  _wrap_new_FieldFunction__SWIG_3 (args=<optimized out>) at /tmp/swig-field-example/build/openturnsPYTHON_wrap.cxx:3097
    #6  _wrap_new_FieldFunction (self=<optimized out>, args=<optimized out>) at /tmp/swig-field-example/build/openturnsPYTHON_wrap.cxx:3141
    #7  0x00000000004c517d in PyCFunction_Call ()
    #8  0x0000000000557c60 in _PyEval_EvalFrameDefault ()
    #9  0x000000000054fbe1 in ?? ()
    #10 0x0000000000558e19 in _PyFunction_FastCallDict ()
    #11 0x000000000045a461 in _PyObject_Call_Prepend ()
    #12 0x0000000000459eee in PyObject_Call ()
    #13 0x00000000004e15bb in ?? ()
    #14 0x00000000004db337 in ?? ()
    #15 0x000000000045a0e3 in _PyObject_FastCallDict ()
    #16 0x000000000054fd37 in ?? ()
    #17 0x00000000005546cf in _PyEval_EvalFrameDefault ()
    #18 0x000000000054fbe1 in ?? ()
    #19 0x0000000000550b93 in PyEval_EvalCode ()
    #20 0x000000000042b519 in PyRun_FileExFlags ()
    #21 0x000000000042b705 in PyRun_SimpleFileExFlags ()
    #22 0x0000000000441fcb in Py_Main ()
    #23 0x0000000000421ff4 in main ()
