#ifndef LINA_SHARED_H
#define LINA_SHARED_H

#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

static inline double TO_RADIANS(double degrees)
{
	return (degrees * (M_PI / (double)180));
}

#endif // LINA_SHARED_H
