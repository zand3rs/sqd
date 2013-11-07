config_files = \
               sqd.conf

EXTRA_DIST = $(config_files)

sysconf_DATA =

# Do not overwrite installed files...
install-data-local:
		$(mkinstalldirs) $(DESTDIR)$(sysconfdir)
		@p="$(config_files)"; \
		for file in $$p; do \
		  if test -f $(DESTDIR)$(sysconfdir)/$$file; then \
		    echo "Not installing $$file over existing $(DESTDIR)$(sysconfdir)/$$file"; \
		  else \
		    if test -f "$$file"; then d=; else d="$(srcdir)/"; fi; \
		    f="`echo $$file | sed -e 's|^.*/||'`"; \
		    echo " $(INSTALL_DATA) $$d$$file $(DESTDIR)$(sysconfdir)/$$f"; \
		    $(INSTALL_DATA) $$d$$file $(DESTDIR)$(sysconfdir)/$$f; \
		  fi; \
		done

# Only remove if exactly the same as what is in the source tree...
uninstall-local:
		@p="$(config_files)"; \
		for file in $$p; do \
		  if test -f "$(DESTDIR)$(sysconfdir)/$$file"; then \
		    if test -f "$$file"; then d=; else d="$(srcdir)/"; fi; \
		    if diff "$(DESTDIR)$(sysconfdir)/$$file" "$$d$$file" > /dev/null 2>&1 ; then \
		      echo "rm -f $(DESTDIR)$(sysconfdir)/$$file" ; \
		      rm -f "$(DESTDIR)$(sysconfdir)/$$file" ; \
		    fi ; \
		  fi ; \
		done

