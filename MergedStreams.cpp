#include <MergedStreams.h>

MergedStreams::MergedStreams(Stream &_p, Stream &_s)
{
  this->p = &_p;
  this->s = &_s;
}

void MergedStreams::setPrimary(Stream &_p)
{
  this->p = &_p;
}

void MergedStreams::setSecondary(Stream &_s)
{
  this->s = &_s;
}

int MergedStreams::available()
{
  return p->available() || s->available();
}

int MergedStreams::peek()
{
  return p->peek() || s->peek();
}

void MergedStreams::flush()
{
  p->flush();
  s->flush();
}

int MergedStreams::read()
{
  if(p->available()){
    return p->read();
  }else{
    return s->read();
  }
}

size_t MergedStreams::write(uint8_t c)
{
  size_t rtn = p->write(c);
  s->write(c);
  return rtn;
}

size_t MergedStreams::write(const char *str)
{
  if (str == NULL) return 0;
  size_t rtn = p->write((const uint8_t *)str, strlen(str));
  s->write((const uint8_t *)str, strlen(str));
  return rtn;
}

size_t MergedStreams::write(const char *buffer, size_t size)
{
  size_t rtn = p->write((const uint8_t *)buffer, size);
  s->write((const uint8_t *)buffer, size);
  return rtn;
}

size_t MergedStreams::write(const uint8_t *buffer, size_t size)
{
  size_t n = 0;
  while (size--) {
    n += p->write(*buffer);
    s->write(*buffer);
    *buffer++;
  }
  return n;
}

size_t MergedStreams::print(const __FlashStringHelper *ifsh)
{
  size_t rtn = p->print(ifsh);
  s->print(ifsh);
  return rtn;
}

size_t MergedStreams::print(const String &string)
{
  size_t rtn = p->print(string);
  s->print(string);
  return rtn;
}

size_t MergedStreams::print(const char str[])
{
  size_t rtn = p->print(str);
  s->print(str);
  return rtn;
}

size_t MergedStreams::print(char c)
{
  size_t rtn = p->print(c);
  s->print(c);
  return rtn;
}

size_t MergedStreams::print(unsigned char b, int base)
{
  size_t rtn = p->print(b, base);
  s->print(b, base);
  return rtn;
}

size_t MergedStreams::print(int n, int base)
{
  size_t rtn = p->print(n, base);
  s->print(n, base);
  return rtn;
}

size_t MergedStreams::print(unsigned int n, int base)
{
  size_t rtn = p->print(n, base);
  s->print(n, base);
  return rtn;
}

size_t MergedStreams::print(long n, int base)
{
  size_t rtn = p->print(n, base);
  s->print(n, base);
  return rtn;
}

size_t MergedStreams::print(unsigned long n, int base)
{
  size_t rtn = p->print(n, base);
  s->print(n, base);
  return rtn;
}

size_t MergedStreams::print(double n, int digits)
{
  size_t rtn = p->print(n, digits);
  s->print(n, digits);
  return rtn;
}

size_t MergedStreams::println(const __FlashStringHelper *ifsh)
{
  size_t rtn = p->println(ifsh);
  s->println(ifsh);
  return rtn;
}

size_t MergedStreams::print(const Printable& x)
{
  size_t rtn = p->print(x);
  s->print(x);
  return rtn;
}

size_t MergedStreams::println(void)
{
  size_t rtn = p->println();
  s->println();
  return rtn;
}

size_t MergedStreams::println(const String &string)
{
  size_t rtn = p->println(string);
  s->println(string);
  return rtn;
}

size_t MergedStreams::println(const char c[])
{
  size_t rtn = p->println(c);
  s->println(c);
  return rtn;
}

size_t MergedStreams::println(char c)
{
  size_t rtn = p->println(c);
  s->println(c);
  return rtn;
}

size_t MergedStreams::println(unsigned char b, int base)
{
  size_t rtn = p->println(b, base);
  s->println(b, base);
  return rtn;
}

size_t MergedStreams::println(int num, int base)
{
  size_t rtn = p->println(num, base);
  s->println(num, base);
  return rtn;
}

size_t MergedStreams::println(unsigned int num, int base)
{
  size_t rtn = p->println(num, base);
  s->println(num, base);
  return rtn;
}

size_t MergedStreams::println(long num, int base)
{
  size_t rtn = p->println(num, base);
  s->println(num, base);
  return rtn;
}

size_t MergedStreams::println(unsigned long num, int base)
{
  size_t rtn = p->println(num, base);
  s->println(num, base);
  return rtn;
}

size_t MergedStreams::println(double num, int digits)
{
  size_t rtn = p->println(num, digits);
  s->println(num, digits);
  return rtn;
}

size_t MergedStreams::println(const Printable& x)
{
  size_t rtn = p->println(x);
  s->println(x);
  return rtn;
}
