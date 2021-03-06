#ifndef _ROS_SERVICE_DigitalWrite_h
#define _ROS_SERVICE_DigitalWrite_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_arduino_msgs
{

static const char DIGITALWRITE[] = "ros_arduino_msgs/DigitalWrite";

  class DigitalWriteRequest : public ros::Msg
  {
    public:
      uint8_t pin;
      bool value;

<<<<<<< HEAD
    DigitalWriteRequest():
      pin(0),
      value(0)
    {
    }

=======
>>>>>>> 114c33badc7e157f5d09deb42c0831bdbf295d3c
    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pin >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pin);
      union {
        bool real;
        uint8_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->pin =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pin);
      union {
        bool real;
        uint8_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    const char * getType(){ return DIGITALWRITE; };
    const char * getMD5(){ return "9965f904e6efea32066b0a4a77246056"; };

  };

  class DigitalWriteResponse : public ros::Msg
  {
    public:

<<<<<<< HEAD
    DigitalWriteResponse()
    {
    }

=======
>>>>>>> 114c33badc7e157f5d09deb42c0831bdbf295d3c
    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return DIGITALWRITE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class DigitalWrite {
    public:
    typedef DigitalWriteRequest Request;
    typedef DigitalWriteResponse Response;
  };

}
#endif
