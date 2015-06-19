#pragma once

typedef struct LedDriverInterfaceDefinition {
  LedState (*state)(LedDriver);
  void (*on)(LedDriver);
  void (*off)(LedDriver);
  void (*destroy)(LedDriver);
} LedDriverInterfaceDefinition;

typedef struct LedDriverInterfaceDefinition* LedDriverInterface;

typedef struct LedDriverInternals {
  LedDriverInterface vtable;
} LedDriverInternals;
