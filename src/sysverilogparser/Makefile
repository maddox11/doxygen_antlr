clean: 
	rm ExprParserParser.cpp ExprLexer.cpp ExprParserListener.cpp ExprParserBaseListener.cpp 
	rm ExprParserParser.h ExprLexer.h ExprParserListener.h ExprParserBaseListener.h 
	rm *.o
	rm *.interp
	rm test



hello_world: 
	/usr/bin/java -Xmx1500M -cp "/usr/local/lib/antlr-4.13.1-complete.jar:$CLASSPATH" org.antlr.v4.Tool   -Dlanguage=Cpp  SysVerilogLexer.g4
	/usr/bin/java -Xmx1500M -cp "/usr/local/lib/antlr-4.13.1-complete.jar:$CLASSPATH" org.antlr.v4.Tool    -Dlanguage=Cpp  MacroLexer.g4
	/usr/bin/java -Xmx1500M -cp "/usr/local/lib/antlr-4.13.1-complete.jar:$CLASSPATH" org.antlr.v4.Tool  -Dlanguage=Cpp  SysVerilog.g4
	
all:hello_world
	

