#include "cpp_odbc/environment.h"

namespace cpp_odbc {

environment::environment() = default;
environment::~environment() = default;

std::shared_ptr<connection const> environment::make_connection(std::string const & connection_string) const
{
	return do_make_connection(connection_string);
}

void environment::set_attribute(SQLINTEGER attribute, long value) const
{
	do_set_attribute(attribute, value);
}



}
