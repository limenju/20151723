//*****************************************************************
// Snake Ver 0.1
// Made by 'k-net 9th' Jae-Dong
// E-Mail: pjd@kw.ac.kr
//*****************************************************************


#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "Manager.h"


int main(int argc, char* argv[])
{
	manager* man = new manager();

	man->Render();

	return 0;
}
