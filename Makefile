OUTPUT = 1
.PHONY: main
main:
	@echo $(OUTPUT)

.PHONY: change
change:
	$(eval OUTPUT += 1)
	@echo $(OUTPUT)

.PHONY: process
process:
	@$(MAKE) main
	@$(MAKE) change
	@$(MAKE) main