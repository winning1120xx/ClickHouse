#pragma once

#include <DB/Parsers/IAST.h>


namespace DB
{

/** Базовый класс для AST, которые могут содержать алиас (идентификаторы, литералы, функции).
  */
class ASTWithAlias : public IAST
{
public:
	/// Алиас, если есть, или пустая строка.
	String alias;

	using IAST::IAST;

	String getAliasOrColumnName() const override 	{ return alias.empty() ? getColumnName() : alias; }
	String tryGetAlias() const override 			{ return alias; }
	void setAlias(const String & to) override 		{ alias = to; }
};

/// helper for setting aliases and chaining result to other functions
inline ASTPtr setAlias(ASTPtr ast, const String & alias) {
	dynamic_cast<ASTWithAlias &>(*ast).alias = alias;

	return ast;
};


}
