#include <iostream>

#include "SqlSelectQueryBuilder.hpp"


int main() {
#if _WIN32
	setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
	std::cout << "\tРеализация SqlSelectQueryBuilder\n" << std::endl;

	SqlSelectQueryBuilder query_builder;

	std::cout << "Вызов методов:\n"
		"\t~.AddColumns({ \"name\", \"phone\" });\n"
		"\t~.AddFrom(\"students\");\n"
		"\t~.AddWhere({ { \"id\", \"42\" }, { \"name\", \"John\" } });\n"
		<< std::endl;
	query_builder.AddColumns({ "name", "phone" });
	query_builder.AddFrom("students");
	query_builder.AddWhere({ {"id", "42" }, { "name", "John" } });
	std::cout << "\tBuild запрос:" << std::endl;
	std::cout << "\t" << query_builder.BuildQuery() << std::endl << std::endl << std::endl;

	std::cout << "Вызов методов:\n"
		"\t~.AddColumns({ \"name\", \"phone\", \"name\", \"phone\" });\n"
		"\t~.AddColumn(\"name\");\n"
		"\t~.AddFrom(\"students\");\n"
		"\t~.AddWhere({ { \"id\", \"42224\" }, { \"name\", \"John\" } });\n"
		"\t~.AddWhere(\"id\", \"42\");\n"
		<< std::endl;
	query_builder.AddColumns({ "name", "phone", "name", "phone" });
	query_builder.AddColumn("name");
	query_builder.AddFrom("students");
	query_builder.AddWhere({ { "id", "42224" }, { "name", "John" } });
	query_builder.AddWhere("id", "42");
	std::cout << "\tBuild запрос:" << std::endl;
	std::cout << "\t" << query_builder.BuildQuery() << std::endl << std::endl << std::endl;

	std::cin.get();
	return 0;
}
