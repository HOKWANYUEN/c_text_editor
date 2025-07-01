.PHONY: clean 
main:
	@make -C src
	@make -C obj
	@echo "done"
clean:
	@rm -r ./obj/*.o
	@rm -f main
