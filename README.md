Getting Started
===============

```
autoreconf --install
make
```

Tests
-----
To run tests, just execute the following after building:

```
make check
```

To verify memory leaks with tests, run:
```
CK_FORK=no valgrind --leak-check=full ./tests/check_LatLngBounds
```

The result should be something like:
```
============================================================================
Testsuite summary for r351574nc3 1.0
============================================================================
# TOTAL: 1
# PASS:  1
# SKIP:  0
# XFAIL: 0
# FAIL:  0
# XPASS: 0
# ERROR: 0
============================================================================
```

The `CK_FORK=no` environment variable prevents Check from forking which prevents orphaned references from the fork which looks like:
```
==17055== Memcheck, a memory error detector
==17055== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==17055== Using Valgrind-3.9.0 and LibVEX; rerun with -h for copyright info
==17055== Command: ./tests/check_LatLngBounds
==17055== 
Running suite(s): LatLngBounds
100%: Checks: 3, Failures: 0, Errors: 0
check_LatLngBounds.c:26:P:Core:lat_in_bounds:0: Passed
check_LatLngBounds.c:11:P:Core:lng_in_bounds:0: Passed
check_LatLngBounds.c:40:P:Core:lng_out_bounds:0: Passed
==17055== 
==17055== HEAP SUMMARY:
==17055==     in use at exit: 0 bytes in 0 blocks
==17055==   total heap usage: 90 allocs, 90 frees, 28,987 bytes allocated
==17055== 
==17055== All heap blocks were freed -- no leaks are possible
==17055== 
==17055== For counts of detected and suppressed errors, rerun with: -v
==17055== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
```

