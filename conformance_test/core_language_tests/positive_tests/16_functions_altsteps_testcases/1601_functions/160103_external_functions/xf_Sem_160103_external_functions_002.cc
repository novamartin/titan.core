/***************************************************
 ** @author   STF 409 
 ** @version  0.0.1
 ** @purpose  1:16.1.3, Ensure that the IUT recognizes external functions
 ** @verdict  pass accept, ttcn3verdict:pass
 ** @configuration  external_functions
 ***************************************************/

#include "Sem_160103_external_functions_002.hh"

namespace Sem__160103__external__functions__002
{

	INTEGER xf__Sem__160103__external__functions__002(INTEGER &p_in)
    {
		return p_in + 1;
	}
}
