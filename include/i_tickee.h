/*
 * i_tickee.h
 *
 * Created: 11/19/2017 9:07:08 PM
 *  Author: nbeth
 */ 


#ifndef I_TICKEE_H_
#define I_TICKEE_H_

class ITickee {
public:
  virtual ~ITickee();
  virtual void tick();
};

#endif /* I_TICKEE_H_ */