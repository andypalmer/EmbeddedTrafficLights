#pragma once

typedef struct LedDriverStruct * LedDriver;

typedef struct {
  void (*on)(LedDriver);
  void (*off)(LedDriver);
  void (*destroy)(LedDriver);
} LedDriverInterface;

typedef struct LedDriverStruct {
  LedDriverInterface vtable;
} LedDriverStruct;

