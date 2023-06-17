PACKAGE = mypcb
VERSION = 3.3.0
TARNAME = $(PACKAGE)
DISTDIR = $(TARNAME)-$(VERSION)

PREFIX = /usr/local
EXEC_PREFIX = $(PREFIX)
BINDIR = $(EXEC_PREFIX)/bin

export PREFIX
export EXEC_PREFIX
export BINDIR

all clean check checkclean install uninstall mypcb:
	cd src && $(MAKE) $@


dist: $(DISTDIR).tar.gz

$(DISTDIR).tar.gz: $(DISTDIR)
	tar chof - $(DISTDIR) | gzip -9 -c > $@
	rm -rf $(DISTDIR)

$(DISTDIR): FORCE
	mkdir -p $(DISTDIR)/src
	mkdir -p $(DISTDIR)/include
	cp Makefile $(DISTDIR)
	cp src/Makefile src/main.c src/Helper.c src/PCBData.c src/PCBFile.c $(DISTDIR)/src
	cp include/Helper.h include/PCBData.h include/PCBFile.h $(DISTDIR)/include
	mkdir -p $(DISTDIR)/etc
	cp etc/example.conf $(DISTDIR)/etc/mypcb.conf

distcheck: $(DISTDIR).tar.gz
	gzip -cd $(DISTDIR).tar.gz | tar xvf -
	cd $(DISTDIR) && $(MAKE) sysconfdir=/tmp/etc outputdir=/tmp all
	cd $(DISTDIR) && $(MAKE) check
	cd $(DISTDIR) && $(MAKE) DESTDIR=$${PWD}/inst install
	cd $(DISTDIR) && $(MAKE) DESTDIR=$${PWD}/inst uninstall
	@remaining="`find $(DISTDIR)/inst -type f | wc -l`"; \
	if test "$${remaining}" -ne 0; then \
	  echo "*** $${remaining} file(s) remaining in stage directory!"; \
	  exit 1;\
	fi
	cd $(DISTDIR) && $(MAKE) clean
	rm -rf $(DISTDIR)
	@echo "*** Package $(DISTDIR).tar.gz is ready for distribution."

distclean:
	-rm $(DISTDIR).tar.gz
	rm -rf $(DISTDIR)

FORCE:
	-rm $(DISTDIR).tar.gz > /dev/null 2>&1
	rm -rf $(DISTDIR)

.PHONY: FORCE all clean check checkclean dist distcheck distclean install uninstall
