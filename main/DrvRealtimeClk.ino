void setCLK(uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second)
{
  // This function is used to set the time of the clock module.
  // Should not be run, when solution is deployed!

  if ((!year) || (!month) || (!day) || (!hour) || (!minute) || (!second))
  {
    return;
  }

  DS3231_init(DS3231_CONTROL_INTCN);

  t.year = year;
  t.mon = month;
  t.mday = day;
  t.hour = hour;
  t.min = minute;
  t.sec = second;

  DS3231_set(t);
}

void readCLK(void)
{
  DS3231_get(&t);
}
