PHP_ARG_ENABLE(nanotime, enable nanotime PHP extension,
[  --enable-nanotime Enable Functional PHP])

if test -z "$PHP_LIBNANOTIME_PREFIX"; then
    PHP_ARG_WITH(libnanotime-prefix, libcld install prefix,
    [  --with-libnanotime-prefix=DIR    nanotime: libnanotime install prefix], no, no)
fi

if test "$PHP_NANOTIME" != "no"; then
    if ! test -f $PHP_LIBNANOTIME_PREFIX/include/libnanotime-1.0.0/nanotime/nanotime.h; then
        AC_MSG_ERROR([libnanotime not found. Specify installation prefix --with-libnanotime-prefix=])
    fi

    AC_DEFINE(HAVE_NANOTIME, 1 ,[Whether you want nanotime support])
    PHP_SUBST(NANOTIME_SHARED_LIBADD)
    PHP_ADD_INCLUDE($PHP_LIBNANOTIME_PREFIX/include/libnanotime-1.0.0)
    PHP_ADD_LIBRARY(nanotime-1.0.0, , NANOTIME_SHARED_LIBADD)

    PHP_NEW_EXTENSION(nanotime, nanotime.c, $ext_shared)
    CFLAGS="$CFLAGS -Wall -g -O0 -pedantic"
fi
