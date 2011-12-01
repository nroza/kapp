include $(top_srcdir)/kapp_common.am

check_PROGRAMS = fib jup
bin_PROGRAMS = gcd

fib_SOURCES = fib.cpp
gcd_SOURCES = gcd.cpp
jup_SOURCES = jup.cpp
jup_CPPFLAGS = -I$(top_srcdir)/include
jup_LDADD = ../jupiter/libjupiter.la
