/*
 * File:    stderr_logger.c
 * Author:  zxsu <suzp1984@gmail.com>
 * Brief:   
 *
 * Copyright (c) zxsu
 *
 * Licensed under the Academic Free License version 2.1
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*
 * History:
 * ================================================================
 * 2013-06-22 18:55 zxsu <suzp1984@gmail.com> created.
 */

#include <stdlib.h>
#include <stdio.h>

#include "stderr_logger.h"

static void stderr_logger_write_message(Logger* thiz, char* msg)
{
    return_if_fail(thiz != NULL);

    printf("stderr_logger: %s\n", msg);
}

static void stderr_logger_destroy(Logger* thiz)
{
    if (thiz->next != NULL) {
        SAFE_FREE(thiz->next);
    }

    SAFE_FREE(thiz);
}

Logger* stderr_logger_create(void)
{
    Logger* thiz = (Logger*) malloc(sizeof(Logger));

    if (thiz != NULL) {
        thiz->mask = 3;
        thiz->next = NULL;
        thiz->write_message = stderr_logger_write_message;

        thiz->destroy = stderr_logger_destroy;
    }

    return thiz;
}
