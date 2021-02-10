lib_LTLIBRARIES = \
	libyasjp.la

libyasjp_la_SOURCES = \
	GrammarParser.cpp \
	LexParser.cpp \
	yasjp.cpp \
	Cast.cpp

nodist_noinst_HEADER = \
	../include/yasjp/impl/LexParser.h

GrammarParser.cpp: yasjp.ypp Makefile
	${BISON} yasjp.ypp \
		--debug --token-table --verbose --feature=fixit \
		-o GrammarParser.cpp

LexParser.cpp: yasjp.lex Makefile
	${FLEX} yasjp.lex \
		-o LexParser.cpp \
		--header-file=../include/yasjp/impl/LexParser.h \
		--debug --perf-report --verbose --language=C++

clean-local:
	${RM} LexParser.cpp
	${RM} GrammarParser.cpp GrammarParser.output GrammarParserLocation.h
	${RM} ../include/yasjp/impl/LexParser.h
