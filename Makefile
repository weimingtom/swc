.PHONY: clean All

All:
	@echo "----------Building project:[ swc - Debug ]----------"
	@cd "swc" && "$(MAKE)" -f  "swc.mk"
clean:
	@echo "----------Cleaning project:[ swc - Debug ]----------"
	@cd "swc" && "$(MAKE)" -f  "swc.mk" clean
