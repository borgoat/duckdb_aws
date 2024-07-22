#include "aws_dynamo.hpp"

#include "duckdb/main/extension_util.hpp"

#include <aws/dynamodb/model/AttributeValue.h>
#include <duckdb/common/vector_operations/generic_executor.hpp>

namespace duckdb {

static void DynamoUnmarshallFun(DataChunk &args, ExpressionState &state, Vector &result) {
	// auto &string_struct = args.data[0];
	// UnaryExecutor::Execute<StructTypeUnary<string_t>, string_t>(], result, args.size(),
	//
	//                                                             [&](StructTypeUnary<string_t> input) {
	// 	                                                            // Unmarshall the input
	// 	                                                            return StringVector::AddString(result, "Something");
	//                                                             });
	StringVector::AddString(result, "Something");
	result.SetVectorType(VectorType::CONSTANT_VECTOR);
}

void DynamoFunctions::Register(DatabaseInstance &instance) {
	ScalarFunctionSet function_set("dynamo_unmarshall");

	auto json_fun = ScalarFunction({LogicalType::STRUCT({{"S", LogicalTypeId::VARCHAR}})}, LogicalTypeId::VARCHAR,
	                               DynamoUnmarshallFun);
	function_set.AddFunction(json_fun);

	ExtensionUtil::RegisterFunction(instance, function_set);
}

} // namespace duckdb
