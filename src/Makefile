BINARY_NAME = mypcb

SOURCES = $(wildcard *.c)
INCLUDES = ../include

CFLAGS = -g -O0
CPPFLAGS = -I $(INCLUDES)

ifndef sysconfdir
sysconfdir=/tmp/etc
endif

ifndef outputdir
outputdir=/tmp
endif

all: $(BINARY_NAME)

install: all
	install -d $(DESTDIR)$(BINDIR)
	install -m 0755 $(BINARY_NAME) $(DESTDIR)$(BINDIR)

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/$(BINARY_NAME)
#	-rmdir $(DESTDIR)$(bindir) > /dev/null 2>&1

check: all
	mkdir -p /tmp/etc
	cp ../etc/example.conf /tmp/etc/mypcb.conf
	./mypcb 2020 12 999988; ls -l /tmp/PCB_202012.txt
	@echo "*** ALL TEST PASSED ***"

checkclean: clean
	-rm /tmp/PCB_202012.txt
	rm -rf /tmp/etc

clean:
	-rm $(BINARY_NAME)

$(BINARY_NAME): $(SOURCES)
	gcc -DCFGDIR="\"$(sysconfdir)\"" -DOUTPUTDIR="\"$(outputdir)\"" $(CFLAGS) $(CPPFLAGS) $(SOURCES) -o $@

.PHONY: all clean check checkclean install uninstall