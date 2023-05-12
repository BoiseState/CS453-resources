// -*-C++-*-

#ifndef BOX_H
#define BOX_H

template <class Item>
class Box {
  Item item;
public:
  void put(Item item);
  Item get();
};

#endif
