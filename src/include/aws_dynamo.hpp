#pragma once

#include "aws_extension.hpp"
#include "duckdb.hpp"

namespace duckdb {

struct DynamoFunctions {
public:
	//! Register all CreateDynamoFunctions
	static void Register(DatabaseInstance &instance);
};

} // namespace duckdb
