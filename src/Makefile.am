lib_LTLIBRARIES = \
	libyasjp.la

libyasjp_la_SOURCES = \
	yasjp.cpp \
	Cast.cpp \
	FlexLexer.cpp

nodist_noinst_HEADER = \
	../include/yasjp/impl/FlexLexer.h

FlexLexer.cpp: yasjp.lex Makefile
	${LEX} \
		--outfile=src/FlexLexer.cpp \
		--header-file=../include/yasjp/impl/FlexLexer.h \
		--debug --perf-report --verbose \
		yasjp.lex

clean-local:
	${RM} src/FlexLexer.cpp
	${RM} ../include/yasjp/impl/FlexLexer.h
