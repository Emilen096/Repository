#include "Person.h"

int main(void)
{
	Person fio ("Tsvetkov", "Emilen", "Maksimovich");
	fio.show();
	fio.showFormal();
    return 0;
}