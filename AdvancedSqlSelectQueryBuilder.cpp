#include "AdvancedSqlSelectQueryBuilder.hpp"


AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereGreater(const std::string& key, const std::string& value) noexcept {
	m_where_Greater[key] = value;
	return *this;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereLess(const std::string& key, const std::string& value) noexcept {
	m_where_Less[key] = value;
	return *this;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereGreaterOrEqual(const std::string& key, const std::string& value) noexcept {
	m_where_GreaterOrEqual[key] = value;
	return *this;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereLessOrEqual(const std::string& key, const std::string& value) noexcept {
	m_where_LessOrEqual[key] = value;
	return *this;
}

std::string AdvancedSqlSelectQueryBuilder::BuildQuery() noexcept {
    if (m_table.empty()) {
        m_column.clear();
        m_where.clear();
        m_where_Greater.clear();
        m_where_Less.clear();
        m_where_GreaterOrEqual.clear();
        m_where_LessOrEqual.clear();
        return "";
    }

    std::string query = "\"SELECT ";

    if (m_column.empty()) {
        query += "* ";
    }
    else {
        for (size_t i = 0; i < m_column.size(); ++i) {
            query += m_column[i];
            if (i == m_column.size() - 1) {
                query += ' ';
            }
            else {
                query += ", ";
            }
        }
    }

    query += "FROM " + m_table;

    if (m_where.empty() && m_where_Greater.empty() && m_where_Less.empty() && m_where_GreaterOrEqual.empty() && m_where_LessOrEqual.empty()) {
        query += ";\"";
    }
    else {
        query += " WHERE ";
        bool where_flag = false;

        for (const auto& it : m_where) {
            if (where_flag) query += " AND ";
            query += it.first + "=\'" + it.second + '\'';
            where_flag = true;
        }

        for (const auto& it : m_where_Greater) {
            if (where_flag) query += " AND ";
            query += it.first + ">\'" + it.second + '\'';
            where_flag = true;
        }

        for (const auto& it : m_where_Less) {
            if (where_flag) query += " AND ";
            query += it.first + "<\'" + it.second + '\'';
            where_flag = true;
        }

        for (const auto& it : m_where_GreaterOrEqual) {
            if (where_flag) query += " AND ";
            query += it.first + ">=\'" + it.second + '\'';
            where_flag = true;
        }

        for (const auto& it : m_where_LessOrEqual) {
            if (where_flag) query += " AND ";
            query += it.first + "<=\'" + it.second + '\'';
            where_flag = true;
        }

        query += ";\"";
    }

    m_table.clear();
    m_column.clear();
    m_where.clear();
    m_where_Greater.clear();
    m_where_Less.clear();
    m_where_GreaterOrEqual.clear();
    m_where_LessOrEqual.clear();
    return query;
}
