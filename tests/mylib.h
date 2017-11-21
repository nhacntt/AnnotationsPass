#pragma once
#include "../include/ProvAnnotations.hh"
#include <cstdlib>

_SOURCE_
int m_read(int fildes, _OUT_ void *buf, size_t nbyte);

_SINK_
int m_write(int fildes, _IN_ const void *buf, size_t nbyte);
