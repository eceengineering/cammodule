/* ============================================================================
 * @File: 	 main.c
 * @Author: 	 Ozgur Eralp [ozgur.eralp@outlook.com]
 * @Description: Camera Interface TEST Application running on ARM Platforms
 *
 * ============================================================================
 *
 * Copyright 2014 Ozgur Eralp.
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * THE COPYRIGHT HOLDERS, AUTHORS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * ============================================================================
 *
 * THIS IS A TEST APPLICATION IMPLEMENTED FOR CAMMODULE
 * ASSUMPTION(S):
 *	- Camera able to capture YUV (UYVY) format.
 *
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <asm/errno.h>
#include "cammodule.h"

int main(int argc, char *argv[])
{
	struct cammodule_arguments camarg;

	/* Initialize CAMMODULE */
    	camarg.width = 640;
	camarg.height = 480;
    	camarg.device_name = (char *)"/dev/video0";
	cammodule_init(&camarg);

	/* Start CAMMODULE */
	cammodule_start();

	/* Get video frame(s) */
	int count = 0;
	int size = (camarg.width)*(camarg.height)*4;
	char * fdata = malloc ((sizeof(char))*size);
	while (count < 2500)
  {
		count++;
		cammodule_getframe(fdata);
		usleep(40000);
	}

	/* Stop CAMMODULE */
	cammodule_stop();

	printf("\n.Good Bye!.\n\n");

	return 0;
}
