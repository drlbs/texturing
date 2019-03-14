#This is the top-level master makefile


# Pull in common definitions

include Makefile.inc

#Define the location of needed directories

lib_soil = lib/SOIL
source = src

.PHONY : all $(lib_soil) $(source)
all : $(source)

$(source) $(lib_soil) :
	$(MAKE) --directory=$@

$(source) : $(lib_soil)

clean:
	cd $(lib_soil) && $(MAKE)  clean
	cd $(source) && $(MAKE)  clean
	
pristine:
	cd $(lib_soil) && $(MAKE) pristine 
	cd $(source) && $(MAKE) pristine
	


