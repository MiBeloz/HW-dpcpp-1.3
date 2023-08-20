#include <iostream>

#include "AdvancedSqlSelectQueryBuilder.hpp"
#include "SqlSelectQueryBuilder.hpp"


int main() {
#if _WIN32
	setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
	std::cout << "\tРеализация AdvancedSqlSelectQueryBuilder\n" << std::endl;

	AdvancedSqlSelectQueryBuilder query_builder;

	std::cout << "Вызов методов:\n"
		"\t~.AddColumns({ \"name\", \"phone\" });\n"
		"\t~.AddFrom(\"students\");\n"
		"\t~.AddWhereGreater(\"id\", \"42\");\n"
		<< std::endl;
	query_builder.AddColumns({ "name", "phone" });
	query_builder.AddFrom("students");
	query_builder.AddWhereGreater("id", "42");
	std::cout << "\tBuild запрос:" << std::endl;
	std::cout << "\t" << query_builder.BuildQuery() << std::endl << std::endl << std::endl;

	std::cout << "Вызов методов:\n"
		"\t~.AddColumns({ \"name\", \"phone\" });\n"
		"\t~.AddFrom(\"students\");\n"
		"\t~.AddWhereGreater(\"id\", \"42\");\n"
		"\t~.AddWhereLess(\"id\", \"96\");\n"
		<< std::endl;
	query_builder.AddColumns({ "name", "phone" });
	query_builder.AddFrom("students");
	query_builder.AddWhereGreater("id", "42");
	query_builder.AddWhereLess("id", "96");
	std::cout << "\tBuild запрос:" << std::endl;
	std::cout << "\t" << query_builder.BuildQuery() << std::endl << std::endl << std::endl;

	std::cout << "Вызов методов:\n"
		"\t~.AddColumns({ \"name\", \"phone\" });\n"
		"\t~.AddFrom(\"students\");\n"
		"\t~.AddWhereGreater(\"id\", \"42\");\n"
		"\t~.AddWhereLess(\"id\", \"96\");\n"
		"\t~.AddWhere(\"phone\", \"123456\");\n"
		<< std::endl;
	query_builder.AddColumns({ "name", "phone" });
	query_builder.AddFrom("students");
	query_builder.AddWhereGreaterOrEqual("id", "42");
	query_builder.AddWhereLessOrEqual("id", "96");
	query_builder.AddWhere("phone", "123456");
	std::cout << "\tBuild запрос:" << std::endl;
	std::cout << "\t" << query_builder.BuildQuery() << std::endl;

	std::cin.get();
	return 0;
}
