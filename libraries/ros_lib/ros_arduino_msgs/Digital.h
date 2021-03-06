#ifndef _ROS_ros_arduino_msgs_Digital_h
#define _ROS_ros_arduino_msgs_Digital_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ros_arduino_msgs
{

  class Digital : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t value;

<<<<<<< HEAD
    Digital():
      header(),
      value(0)
    {
    }

=======
>>>>>>> 114c33badc7e157f5d09deb42c0831bdbf295d3c
    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->value >> (8 * 0)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->value =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->value);
     return offset;
    }

    const char * getType(){ return "ros_arduino_msgs/Digital"; };
    const char * getMD5(){ return "90539346f3c3c8fc47f159ab9a6ff208"; };

  };

}
#endif