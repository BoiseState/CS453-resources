/*
  https://raw.githubusercontent.com/smartmobili/parsing/master/Flex%20Bison/Java.y
*/

/*
 * Godiva Grammar: godgram.y
 *
 * Based on Java grammar in Gosling/Joy/Steele, Chapter 19
 */

%{
#include 
#include "tree.h"
%}

/*
 * %union declares of what kinds of values appear on the value stack
 */
%union {
   nodeptr node;
   }

/*
 * each token is declared.  tokens store leaf values on the value stack
 *
 * Back in javalex.l, we put things on the stack by assigning to yylval

 "abstract"           { yylval.node = alcnode(ABSTRACT, 0); return ABSTRACT; }

 *
 */
%token < node > ABSTRACT BOOLEAN BREAK BYTE CASE CATCH CHAR CLASS CONST
%token < node > DEFAULT DO DOUBLE ELSE EXTENDS FINAL FINALLY FLOAT FOR GOTO
%token < node > IF IMPLEMENTS IMPORT INSTANCEOF INT INTERFACE LONG NATIVE NEW
%token < node > PACKAGE PRIVATE PROTECTED PUBLIC RETURN SUSPEND
%token < node > SHORT STATIC SUPER SWITCH SYNCHRONIZED THIS THROW THROWS
%token < node > VOID VOLATILE WHILE IDENT CONTINUE TRANSIENT TRY
%token < node > NULLLITERAL BOOLLITERAL INTLITERAL
%token < node > CHARLITERAL FLOATLITERAL STRINGLITERAL
%token < node > LP RP LC RC LB RB SM CM DOT ASN LT GT BANG TILDE QUEST COLON
%token < node > EQ NE LE GE ANDAND OROR INC DEC PLUS MINUS MUL DIV AND OR CARET
%token < node > MOD SHL SHR LSHR PLASN MIASN MUASN DIASN ANDASN ORASN CARETASN
%token < node > SLASN SRASN LSRASN MODASN BAD_TOKEN

/*
 * each nonterminal is declared.  nonterminals correspond to internal nodes
 */
%type < node > Goal Literal Type PrimitiveType NumericType IntegralType
%type < node > FloatingPointType ReferenceType ClassOrInterfaceType
%type < node > ClassType InterfaceType ArrayType Name SimpleName
%type < node > QualifiedName CompilationUnit ImportDeclarations
%type < node > TypeDeclarations PackageDeclaration ImportDeclaration
%type < node > SingleTypeImportDeclaration TypeImportOnDemandDeclaration
%type < node > TypeDeclaration Modifiers Modifier ClassDeclaration
%type < node > Super Interfaces InterfaceTypeList ClassBody
%type < node > ClassBodyDeclarations ClassBodyDeclaration
%type < node > ClassMemberDeclaration FieldDeclaration VariableDeclarators
%type < node > VariableDeclarator VariableDeclaratorId VariableInitializer
%type < node > MethodDeclaration MethodHeader MethodDeclarator
%type < node > FormalParameterList FormalParameter Throws ClassTypeList
%type < node > MethodBody StaticInitializer ConstructorDeclaration
%type < node > ConstructorDeclarator ConstructorBody
%type < node > ExplicitConstructorInvocation InterfaceDeclaration
%type < node > ExtendsInterfaces InterfaceBody InterfaceMemberDeclarations
%type < node > InterfaceMemberDeclaration ConstantDeclaration
%type < node > AbstractMethodDeclaration ArrayInitializer
%type < node > VariableInitializers Block BlockStatements BlockStatement
%type < node > LocalVariableDeclarationStatement LocalVariableDeclaration
%type < node > Statement StatementNoShortIf
%type < node > StatementWithoutTrailingSubstatement EmptyStatement
%type < node > LabeledStatement LabeledStatementNoShortIf
%type < node > ExpressionStatement StatementExpression IfThenStatement
%type < node > IfThenElseStatement IfThenElseStatementNoShortIf
%type < node > SwitchStatement SwitchBlock SwitchBlockStatementGroups
%type < node > SwitchBlockStatementGroup SwitchLabels SwitchLabel
%type < node > WhileStatement WhileStatementNoShortIf DoStatement
%type < node > ForStatement ForStatementNoShortIf ForInit ForUpdate
%type < node > StatementExpressionList BreakStatement ContinueStatement
%type < node > ReturnStatement ThrowStatement SynchronizedStatement
%type < node > TryStatement Catches CatchClause Finally Primary
%type < node > PrimaryNoNewArray ClassInstanceCreationExpression
%type < node > ArgumentList ArrayCreationExpression DimExprs DimExpr Dims
%type < node > FieldAccess MethodInvocation ArrayAccess PostFixExpression
%type < node > PostIncrementExpression PostDecrementExpression
%type < node > UnaryExpression PreIncrementExpression PreDecrementExpression
%type < node > UnaryExpressionNotPlusMinus CastExpression
%type < node > MultiplicativeExpression AdditiveExpression ShiftExpression
%type < node > RelationalExpression EqualityExpression AndExpression
%type < node > ExclusiveOrExpression InclusiveOrExpression
%type < node > ConditionalAndExpression ConditionalOrExpression
%type < node > ConditionalExpression AssignmentExpression Assignment
%type < node > LeftHandSide AssignmentOperator Expression ConstantExpression
%type < node > PackageDeclarationOpt ImportDeclarationsOpt TypeDeclarationsOpt
%type < node > ModifiersOpt SuperOpt InterfacesOpt ClassBodyDeclarationsOpt
%type < node > ThrowsOpt FormalParameterListOpt IDENTOpt CatchesOpt
%type < node > ExplicitConstructorInvocationOpt BlockStatementsOpt
%type < node > ArgumentListOpt ExplicitConstructorInvocationOpt DimsOpt
%type < node > ExtendsInterfacesOpt InterfaceMemberDeclarationsOpt
%type < node > VariableInitializersOpt CMOpt SwitchBlockStatementGroupsOpt
%type < node > SwitchLabelsOpt ForInitOpt ExpressionOpt ForUpdateOpt

/*
 * the start symbol, Goal, may seem to be here for rhetorical purposes,
 * but it is also the ideal spot to insert a semantic action that passes
 * the completed parse tree to a later phase of compilation.
 */
%start Goal

%%

Goal:		  CompilationUnit
		;

Literal:	  INTLITERAL
		| FLOATLITERAL
		| BOOLLITERAL
		| STRINGLITERAL
		| CHARLITERAL
		| NULLLITERAL
		;
	
Type:		  PrimitiveType
		| ReferenceType
		;

PrimitiveType:	  NumericType
		| BOOLEAN
		;

NumericType:	  IntegralType
		| FloatingPointType
		;

IntegralType:	  BYTE
		| SHORT
		| INT
		| LONG
		| CHAR
		;

FloatingPointType: FLOAT
		| DOUBLE
		;

ReferenceType:	  ClassOrInterfaceType
		| ArrayType
		;

ClassOrInterfaceType: Name
		;

ClassType:	  ClassOrInterfaceType
		;

InterfaceType:	  ClassOrInterfaceType
		;

ArrayType:	  PrimitiveType LB RB
		| Name LB RB
		| ArrayType LB RB
		;

Name:		  SimpleName
		| QualifiedName
		;

SimpleName:	  IDENT
		;

QualifiedName:	  Name DOT IDENT
		;

CompilationUnit:  PackageDeclarationOpt
			ImportDeclarationsOpt TypeDeclarationsOpt
		;

PackageDeclarationOpt: PackageDeclaration | { $$ = NULL; } ;

ImportDeclarationsOpt: ImportDeclarations | { $$ = NULL; } ;

TypeDeclarationsOpt: TypeDeclarations | { $$ = NULL; } ;

ImportDeclarations: ImportDeclaration
		| ImportDeclarations ImportDeclaration
		;

TypeDeclarations: TypeDeclaration
		| TypeDeclarations TypeDeclaration
		;

PackageDeclaration: PACKAGE Name SM
		;

ImportDeclaration: SingleTypeImportDeclaration
		| TypeImportOnDemandDeclaration
		;

SingleTypeImportDeclaration: IMPORT Name SM
		;

TypeImportOnDemandDeclaration: IMPORT Name DOT MUL SM
		;

TypeDeclaration:  ClassDeclaration
		| InterfaceDeclaration
		;

Modifiers: Modifier
		| Modifiers Modifier
		;

Modifier:	  PUBLIC
		| PROTECTED
		| PRIVATE
		| STATIC
		| ABSTRACT
		| FINAL
		| NATIVE
		| SYNCHRONIZED
		| TRANSIENT
		| VOLATILE
		;

ClassDeclaration: ModifiersOpt CLASS IDENT SuperOpt InterfacesOpt ClassBody
		;

ModifiersOpt: Modifiers | { $$ = NULL; } ;

SuperOpt:	  Super | { $$ = NULL; } ;

InterfacesOpt:	  Interfaces | { $$ = NULL; } ;

Super:		  EXTENDS ClassType
		;

Interfaces:	  IMPLEMENTS InterfaceTypeList
		;

InterfaceTypeList: InterfaceType
		| InterfaceTypeList CM InterfaceType
		;

ClassBody:	  LC ClassBodyDeclarationsOpt RC
		;

ClassBodyDeclarationsOpt: ClassBodyDeclarations | { $$ = NULL; } ;

ClassBodyDeclarations: ClassBodyDeclaration
		| ClassBodyDeclarations ClassBodyDeclaration
		;

ClassBodyDeclaration: ClassMemberDeclaration
		| StaticInitializer
		| ConstructorDeclaration
		;

ClassMemberDeclaration: FieldDeclaration
		| MethodDeclaration
		;

FieldDeclaration: ModifiersOpt Type VariableDeclarators SM
		;

VariableDeclarators: VariableDeclarator
		| VariableDeclarators CM VariableDeclarator
		;

VariableDeclarator: VariableDeclaratorId
		| VariableDeclaratorId ASN VariableInitializer
		;

VariableDeclaratorId: IDENT
		| VariableDeclaratorId LB RB
		;

VariableInitializer: Expression
		| ArrayInitializer
		;

MethodDeclaration: MethodHeader MethodBody
		;

MethodHeader: ModifiersOpt Type MethodDeclarator ThrowsOpt
		|  ModifiersOpt VOID MethodDeclarator ThrowsOpt
		;


ThrowsOpt:	  Throws | { $$ = NULL; } ;


FormalParameterListOpt: FormalParameterList | { $$ = NULL; } ;

MethodDeclarator: IDENT LP FormalParameterListOpt RP
		| MethodDeclarator LB RB
		;

FormalParameterList: FormalParameter
		| FormalParameterList CM FormalParameter
		;

FormalParameter: Type VariableDeclaratorId
		;


Throws: THROWS ClassTypeList
		;


ClassTypeList: ClassType
		| ClassTypeList CM ClassType
		;

MethodBody: Block
		;

StaticInitializer: STATIC Block
		;

ConstructorDeclaration: ModifiersOpt ConstructorDeclarator
				ThrowsOpt ConstructorBody
		;

ConstructorDeclarator: SimpleName LP FormalParameterListOpt RP
		;

ExplicitConstructorInvocationOpt: ExplicitConstructorInvocation | { $$ = NULL; } ;

BlockStatementsOpt: BlockStatements | { $$ = NULL; } ;

ArgumentListOpt:  ArgumentList | { $$ = NULL; } ;

ConstructorBody: LC ExplicitConstructorInvocationOpt BlockStatementsOpt RC
		;

ExplicitConstructorInvocation: THIS LP ArgumentListOpt RP SM
		| SUPER LP ArgumentListOpt RP SM
		;

ExtendsInterfacesOpt: ExtendsInterfaces | { $$ = NULL; } ;

InterfaceDeclaration: ModifiersOpt INTERFACE IDENT
			ExtendsInterfacesOpt InterfaceBody
		;

ExtendsInterfaces: EXTENDS InterfaceType
		| ExtendsInterfaces CM InterfaceType
		;

InterfaceMemberDeclarationsOpt: InterfaceMemberDeclarations | { $$ = NULL; } ;

InterfaceBody: LC InterfaceMemberDeclarationsOpt RC
		;

InterfaceMemberDeclarations: InterfaceMemberDeclaration
		| InterfaceMemberDeclarations InterfaceMemberDeclaration
		;

InterfaceMemberDeclaration: ConstantDeclaration
		| AbstractMethodDeclaration
		;

ConstantDeclaration: FieldDeclaration
		;

AbstractMethodDeclaration: MethodHeader SM
		;

VariableInitializersOpt: VariableInitializers | { $$ = NULL; } ;

CMOpt:	CM { $$ = NULL; } | { $$ = NULL; } ;

ArrayInitializer: LC VariableInitializersOpt CMOpt RC
		;

VariableInitializers: VariableInitializer
		| VariableInitializers CM VariableInitializer
		;

Block:		  LC BlockStatementsOpt RC
		;

BlockStatements:  BlockStatement
		| BlockStatements BlockStatement
		;

BlockStatement:   LocalVariableDeclarationStatement
		| Statement
		;

LocalVariableDeclarationStatement: LocalVariableDeclaration SM
		;

LocalVariableDeclaration: Type VariableDeclarators
		;

Statement:	  StatementWithoutTrailingSubstatement
		| LabeledStatement
		| IfThenStatement
		| IfThenElseStatement
		| WhileStatement
		| ForStatement
		;

StatementNoShortIf: StatementWithoutTrailingSubstatement
		| LabeledStatementNoShortIf
		| IfThenElseStatementNoShortIf
		| WhileStatementNoShortIf
		| ForStatementNoShortIf
		;

StatementWithoutTrailingSubstatement: Block
		| EmptyStatement
		| ExpressionStatement
		| SwitchStatement
		| DoStatement
		| BreakStatement
		| ContinueStatement
		| ReturnStatement
		| SynchronizedStatement
		| ThrowStatement
		| TryStatement
		;

EmptyStatement:	  SM
		;

LabeledStatement: IDENT COLON Statement
		;

LabeledStatementNoShortIf: IDENT COLON StatementNoShortIf
		;

ExpressionStatement: StatementExpression SM
		;

StatementExpression: Assignment
		| PreIncrementExpression
		| PreDecrementExpression
		| PostIncrementExpression
		| PostDecrementExpression
		| MethodInvocation
		| ClassInstanceCreationExpression
		;

IfThenStatement:  IF LP Expression RP Statement
		;

IfThenElseStatement:  IF LP Expression RP StatementNoShortIf ELSE Statement
		;

IfThenElseStatementNoShortIf:  IF LP Expression RP StatementNoShortIf
			ELSE StatementNoShortIf
		;

SwitchStatement:  SWITCH LP Expression RP SwitchBlock
		;

SwitchBlockStatementGroupsOpt: SwitchBlockStatementGroups | { $$ = NULL; } ;

SwitchLabelsOpt: SwitchLabels | { $$ = NULL; } ;

SwitchBlock:	  LC SwitchBlockStatementGroupsOpt SwitchLabelsOpt RC
		;

SwitchBlockStatementGroups: SwitchBlockStatementGroup
		| SwitchBlockStatementGroups SwitchBlockStatementGroup
		;

SwitchBlockStatementGroup: SwitchLabels BlockStatements
		;

SwitchLabels:	  SwitchLabel
		| SwitchLabels SwitchLabel
		;

SwitchLabel:	  CASE ConstantExpression COLON
		| DEFAULT COLON
		;

WhileStatement:	  WHILE LP Expression RP Statement
		;

WhileStatementNoShortIf:  WHILE LP Expression RP StatementNoShortIf
		;

DoStatement:	  DO Statement WHILE LP Expression RP SM
		;

ForInitOpt: ForInit | { $$ = NULL; } ;

ExpressionOpt: Expression | { $$ = NULL; } ;

ForUpdateOpt: ForUpdate | { $$ = NULL; } ;

ForStatement:	  FOR LP ForInitOpt SM ExpressionOpt SM ForUpdateOpt RP
			Statement
		;

ForStatementNoShortIf:	  FOR LP ForInitOpt SM ExpressionOpt SM ForUpdateOpt RP
			StatementNoShortIf
		;


ForInit:	  StatementExpressionList
		| LocalVariableDeclaration
		;

ForUpdate:	  StatementExpressionList
		;

StatementExpressionList: StatementExpression
		| StatementExpressionList CM StatementExpression
		;

IDENTOpt: IDENT | { $$ = NULL; } ;

BreakStatement:	  BREAK IDENTOpt SM
		;

ContinueStatement: CONTINUE IDENTOpt SM
		;

ReturnStatement:  RETURN ExpressionOpt SM
		| SUSPEND ExpressionOpt SM
		;


ThrowStatement:  THROW Expression SM
		;

SynchronizedStatement:  SYNCHRONIZED LP Expression RP Block
		;

CatchesOpt: Catches | { $$ = NULL; } ;

TryStatement:	  TRY Block Catches
		| TRY Block CatchesOpt Finally
		;
Catches:	  CatchClause
		| Catches CatchClause
		;

CatchClause:	  CATCH LP FormalParameter RP Block

		;

Finally:	  FINALLY Block
		;

Primary:	  PrimaryNoNewArray
		| ArrayCreationExpression
		;

PrimaryNoNewArray: Literal
		| THIS
		| LP Expression RP
		| ClassInstanceCreationExpression
		| FieldAccess
		| MethodInvocation
		| ArrayAccess
		;

ClassInstanceCreationExpression: NEW ClassType LP ArgumentListOpt RP
		;

ArgumentList:	  Expression
		| ArgumentList CM Expression
		;

DimsOpt: Dims | { $$ = NULL; } ;

ArrayCreationExpression: NEW PrimitiveType DimExprs DimsOpt
		| NEW ClassOrInterfaceType DimExprs DimsOpt
		;

DimExprs:	  DimExpr
		| DimExprs DimExpr
		;

DimExpr:	  LB Expression RB
		;

Dims:		  LB RB
		| Dims LB RB
		;

FieldAccess:	  Primary DOT IDENT
		| SUPER DOT IDENT
		;

MethodInvocation: Name LP ArgumentListOpt RP
		| Primary DOT IDENT LP ArgumentListOpt RP
		| SUPER DOT IDENT LP ArgumentListOpt RP
		| Name LC ArgumentListOpt RC
		| Primary DOT IDENT LC ArgumentListOpt RC
		| SUPER DOT IDENT LC ArgumentListOpt RC
		;

ArrayAccess:	  Name LB Expression RB
		| PrimaryNoNewArray LB Expression RB
		;

PostFixExpression: Primary
		| Name
		| PostIncrementExpression
		| PostDecrementExpression
		;

PostIncrementExpression: PostFixExpression INC
		;

PostDecrementExpression: PostFixExpression DEC
		;

UnaryExpression:  PreIncrementExpression
		| PreDecrementExpression
		| PLUS UnaryExpression
		| MINUS UnaryExpression
		| UnaryExpressionNotPlusMinus
		;

PreIncrementExpression: INC UnaryExpression
		;

PreDecrementExpression: DEC UnaryExpression
		;

UnaryExpressionNotPlusMinus: PostFixExpression
		| TILDE UnaryExpression
		| BANG UnaryExpression
		| CastExpression
		;

CastExpression:   LP PrimitiveType DimsOpt RP UnaryExpression
		| LP Expression RP UnaryExpressionNotPlusMinus
		| LP Name Dims RP UnaryExpressionNotPlusMinus
		;

MultiplicativeExpression: UnaryExpression
		| MultiplicativeExpression MUL UnaryExpression
		| MultiplicativeExpression DIV UnaryExpression
		| MultiplicativeExpression MOD UnaryExpression
		;

AdditiveExpression: MultiplicativeExpression
		| AdditiveExpression PLUS MultiplicativeExpression
		| AdditiveExpression MINUS MultiplicativeExpression
		;

ShiftExpression:  AdditiveExpression
		| ShiftExpression SHL AdditiveExpression
		| ShiftExpression SHR AdditiveExpression
		| ShiftExpression LSHR AdditiveExpression
		;

RelationalExpression: ShiftExpression
		| RelationalExpression LT ShiftExpression
		| RelationalExpression GT ShiftExpression
		| RelationalExpression LE ShiftExpression
		| RelationalExpression GE ShiftExpression
		| RelationalExpression INSTANCEOF ReferenceType
		;

EqualityExpression: RelationalExpression
		| EqualityExpression EQ RelationalExpression
		| EqualityExpression NE RelationalExpression
		;

AndExpression: EqualityExpression
		| AndExpression AND EqualityExpression
		;

ExclusiveOrExpression: AndExpression
		| ExclusiveOrExpression CARET AndExpression
		;

InclusiveOrExpression: ExclusiveOrExpression
		| InclusiveOrExpression OR ExclusiveOrExpression
		;

ConditionalAndExpression: InclusiveOrExpression
		| ConditionalAndExpression ANDAND InclusiveOrExpression
		;

ConditionalOrExpression: ConditionalAndExpression
		| ConditionalOrExpression OROR ConditionalAndExpression
		;

ConditionalExpression: ConditionalOrExpression
		| ConditionalOrExpression QUEST Expression
			COLON ConditionalExpression
		;

AssignmentExpression: ConditionalExpression
		| Assignment
		;

Assignment:	  LeftHandSide AssignmentOperator AssignmentExpression
		;

LeftHandSide:	  Name
		| FieldAccess
		| ArrayAccess
		;

AssignmentOperator: ASN
		| MUASN
		| DIASN
		| MODASN
		| PLASN
		| MIASN
		| SLASN
		| SRASN
		| LSRASN
		| ANDASN
		| CARETASN
		| ORASN
		;

Expression:	  AssignmentExpression
		;

ConstantExpression: Expression
		;

