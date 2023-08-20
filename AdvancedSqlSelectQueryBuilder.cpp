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

    if (m_where_Greater.empty() && m_where_Less.empty() && m_where_GreaterOrEqual.empty() && m_where_LessOrEqual.empty()) {
        query += ";\"";
    }
    else {
        query += " WHERE ";
        size_t i = 0;
        for (const auto& it : m_where_Greater) {
            i++;
            query += it.first + '>' + it.second;
            if (i == m_where_Greater.size()) {
                i = 0;
            }
            else {
                query += " AND ";
            }
        }

        if (!m_where_Greater.empty()) {
            query += " AND ";
        }
        for (const auto& it : m_where_Less) {
            i++;
            query += it.first + '<' + it.second;
            if (i == m_where_Less.size()) {
                i = 0;
            }
            else {
                query += " AND ";
            }
        }

        if (!m_where_Greater.empty() || !m_where_Less.empty()) {
            query += " AND ";
        }
        for (const auto& it : m_where_GreaterOrEqual) {
            i++;
            query += it.first + '<' + it.second;
            if (i == m_where_GreaterOrEqual.size()) {
                i = 0;
            }
            else {
                query += " AND ";
            }
        }

        if (!m_where_Greater.empty() || !m_where_Less.empty() || m_where_GreaterOrEqual.empty()) {
            query += " AND ";
        }
        for (const auto& it : m_where_LessOrEqual) {
            i++;
            query += it.first + '<' + it.second;
            if (i == m_where_LessOrEqual.size()) {
                i = 0;
            }
            else {
                query += " AND ";
            }
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
