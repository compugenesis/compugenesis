/*
 * error_handle.c
 *
 *  Created on: Aug 7, 2018
 *      Author: gpi
 */

#include <errno.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vulkan/vulkan.h>

#include "constants.h"

#include "errors.h"

void errLog(uint32_t level, const char *message, ...) {
  char *errmsg;
  FILE *out;

  switch (level) {
  case DEBUG: {
    errmsg = DEBUG_MSG;
    out = stdout;
    break;
  }
  case INFO: {
    errmsg = INFO_MSG;
    out = stdout;
    break;
  }
  case WARN: {
    errmsg = WARN_MSG;
    out = stderr;
    break;
  }
  case ERROR: {
    errmsg = ERROR_MSG;
    out = stderr;
    break;
  }
  case FATAL: {
    errmsg = FATAL_MSG;
    out = stderr;
    break;
  }
  default: {
    errmsg = INFO_MSG;
    out = stdout;
    break;
  }
  }

  char message_formatted[MAX_PRINT_LENGTH];
  va_list args;
  va_start(args, message);
  vsnprintf(message_formatted, MAX_PRINT_LENGTH, message, args);
  va_end(args);

  fprintf(out, "%s: %s: %s\n", APPNAME, errmsg, message_formatted);
}

void panic() { exit(EXIT_FAILURE); }
