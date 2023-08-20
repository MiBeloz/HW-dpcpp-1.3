#pragma once

#include "SqlSelectQueryBuilder.hpp"


class AdvancedSqlSelectQueryBuilder final: public SqlSelectQueryBuilder {
public:
	AdvancedSqlSelectQueryBuilder() = default;
	~AdvancedSqlSelectQueryBuilder() {}

	AdvancedSqlSelectQueryBuilder(const AdvancedSqlSelectQueryBuilder& other) = delete;
	AdvancedSqlSelectQueryBuilder(AdvancedSqlSelectQueryBuilder&& other) noexcept = delete;
	AdvancedSqlSelectQueryBuilder& operator=(const AdvancedSqlSelectQueryBuilder& other) = delete;
	AdvancedSqlSelectQueryBuilder& operator=(AdvancedSqlSelectQueryBuilder&& other) noexcept = delete;

	AdvancedSqlSelectQueryBuilder& AddWhereGreater(const std::string& key, const std::string& value) noexcept;
	AdvancedSqlSelectQueryBuilder& AddWhereLess(const std::string& key, const std::string& value) noexcept;
	AdvancedSqlSelectQueryBuilder& AddWhereGreaterOrEqual(const std::string& key, const std::string& value) noexcept;
	AdvancedSqlSelectQueryBuilder& AddWhereLessOrEqual(const std::string& key, const std::string& value) noexcept;

	std::string BuildQuery() noexcept override;

private:
	std::map<std::string, std::string> m_where_Greater;
	std::map<std::string, std::string> m_where_Less;
	std::map<std::string, std::string> m_where_GreaterOrEqual;
	std::map<std::string, std::string> m_where_LessOrEqual;
};