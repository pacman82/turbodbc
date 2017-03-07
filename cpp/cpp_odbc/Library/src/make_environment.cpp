/**
 *  @file make_environment.cpp
 *  @date 12.12.2014
 *  @author mkoenig
 *  @brief 
 *
 *  $LastChangedDate$
 *  $LastChangedBy$
 *  $LastChangedRevision$
 *
 */

#include "cpp_odbc/make_environment.h"

#include "cpp_odbc/level1/unixodbc_backend.h"
#include "cpp_odbc/level1/unixodbc_backend_debug.h"
#include "cpp_odbc/level2/level1_connector.h"
#include "cpp_odbc/level3/raii_environment.h"


namespace cpp_odbc {

std::shared_ptr<environment> make_environment()
{
  // Don't use make_shared due to http://bugs.llvm.org/show_bug.cgi?id=24137
	auto level1_api = std::shared_ptr<level1::unixodbc_backend const>(new level1::unixodbc_backend());
	auto level2_api = std::make_shared<level2::level1_connector const>(level1_api);
	return std::make_shared<level3::raii_environment>(level2_api);
}

std::shared_ptr<environment> make_debug_environment()
{
  // Don't use make_shared due to http://bugs.llvm.org/show_bug.cgi?id=24137
	auto level1_api = std::shared_ptr<level1::unixodbc_backend_debug const>(new level1::unixodbc_backend_debug());
	auto level2_api = std::make_shared<level2::level1_connector const>(level1_api);
	return std::make_shared<level3::raii_environment>(level2_api);
}

}
