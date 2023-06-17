BINARY_NAME = mypcb

SOURCES = $(wildcard *.c)

CFLAGS = -g -O0

all: $(BINARY_NAME)

install: all
	install -d $(DESTDIR)$(bindir)
	install -m 0755 $(BINARY_NAME) $(DESTDIR)$(bindir)

uninstall:
	rm -f $(DESTDIR)$(bindir)/$(BINARY_NAME)
#	-rmdir $(DESTDIR)$(bindir) > /dev/null 2>&1

check: all
	mkdir /tmp/etc
	cp ../etc/mypcb.conf /tmp/etc/
	./mypcb 2020 12 999988; ls -l /tmp/PCB_202012.txt
	@echo "*** ALL TEST PASSED ***"

checkclean: clean
	-rm /tmp/PCB_202012.txt
	rm -rf /tmp/etc

clean:
	-rm $(BINARY_NAME)

$(BINARY_NAME): $(SOURCES)
	gcc -DCFGDIR="\"$(sysconfdir)\"" -DOUTPUTDIR="\"$(outputdir)\"" $(CFLAGS) -o $@ $(SOURCES)

.PHONY: all clean check checkclean install uninstall