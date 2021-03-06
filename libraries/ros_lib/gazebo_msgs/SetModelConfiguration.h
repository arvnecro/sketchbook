#ifndef _ROS_SERVICE_SetModelConfiguration_h
#define _ROS_SERVICE_SetModelConfiguration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace gazebo_msgs
{

static const char SETMODELCONFIGURATION[] = "gazebo_msgs/SetModelConfiguration";

  class SetModelConfigurationRequest : public ros::Msg
  {
    public:
<<<<<<< HEAD
      const char* model_name;
      const char* urdf_param_name;
=======
      char * model_name;
      char * urdf_param_name;
>>>>>>> 114c33badc7e157f5d09deb42c0831bdbf295d3c
      uint8_t joint_names_length;
      char* st_joint_names;
      char* * joint_names;
      uint8_t joint_positions_length;
      float st_joint_positions;
      float * joint_positions;

<<<<<<< HEAD
    SetModelConfigurationRequest():
      model_name(""),
      urdf_param_name(""),
      joint_names_length(0), joint_names(NULL),
      joint_positions_length(0), joint_positions(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_model_name = strlen(this->model_name);
=======
    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_model_name = strlen( (const char*) this->model_name);
>>>>>>> 114c33badc7e157f5d09deb42c0831bdbf295d3c
      memcpy(outbuffer + offset, &length_model_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->model_name, length_model_name);
      offset += length_model_name;
<<<<<<< HEAD
      uint32_t length_urdf_param_name = strlen(this->urdf_param_name);
=======
      uint32_t length_urdf_param_name = strlen( (const char*) this->urdf_param_name);
>>>>>>> 114c33badc7e157f5d09deb42c0831bdbf295d3c
      memcpy(outbuffer + offset, &length_urdf_param_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->urdf_param_name, length_urdf_param_name);
      offset += length_urdf_param_name;
      *(outbuffer + offset++) = joint_names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joint_names_length; i++){
<<<<<<< HEAD
      uint32_t length_joint_namesi = strlen(this->joint_names[i]);
=======
      uint32_t length_joint_namesi = strlen( (const char*) this->joint_names[i]);
>>>>>>> 114c33badc7e157f5d09deb42c0831bdbf295d3c
      memcpy(outbuffer + offset, &length_joint_namesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->joint_names[i], length_joint_namesi);
      offset += length_joint_namesi;
      }
      *(outbuffer + offset++) = joint_positions_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joint_positions_length; i++){
<<<<<<< HEAD
      offset += serializeAvrFloat64(outbuffer + offset, this->joint_positions[i]);
=======
      int32_t * val_joint_positionsi = (int32_t *) &(this->joint_positions[i]);
      int32_t exp_joint_positionsi = (((*val_joint_positionsi)>>23)&255);
      if(exp_joint_positionsi != 0)
        exp_joint_positionsi += 1023-127;
      int32_t sig_joint_positionsi = *val_joint_positionsi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_joint_positionsi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_joint_positionsi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_joint_positionsi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_joint_positionsi<<4) & 0xF0) | ((sig_joint_positionsi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_joint_positionsi>>4) & 0x7F;
      if(this->joint_positions[i] < 0) *(outbuffer + offset -1) |= 0x80;
>>>>>>> 114c33badc7e157f5d09deb42c0831bdbf295d3c
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_model_name;
      memcpy(&length_model_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model_name-1]=0;
      this->model_name = (char *)(inbuffer + offset-1);
      offset += length_model_name;
      uint32_t length_urdf_param_name;
      memcpy(&length_urdf_param_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_urdf_param_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_urdf_param_name-1]=0;
      this->urdf_param_name = (char *)(inbuffer + offset-1);
      offset += length_urdf_param_name;
      uint8_t joint_names_lengthT = *(inbuffer + offset++);
      if(joint_names_lengthT > joint_names_length)
        this->joint_names = (char**)realloc(this->joint_names, joint_names_lengthT * sizeof(char*));
      offset += 3;
      joint_names_length = joint_names_lengthT;
      for( uint8_t i = 0; i < joint_names_length; i++){
      uint32_t length_st_joint_names;
      memcpy(&length_st_joint_names, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_joint_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_joint_names-1]=0;
      this->st_joint_names = (char *)(inbuffer + offset-1);
      offset += length_st_joint_names;
        memcpy( &(this->joint_names[i]), &(this->st_joint_names), sizeof(char*));
      }
      uint8_t joint_positions_lengthT = *(inbuffer + offset++);
      if(joint_positions_lengthT > joint_positions_length)
        this->joint_positions = (float*)realloc(this->joint_positions, joint_positions_lengthT * sizeof(float));
      offset += 3;
      joint_positions_length = joint_positions_lengthT;
      for( uint8_t i = 0; i < joint_positions_length; i++){
<<<<<<< HEAD
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_joint_positions));
=======
      uint32_t * val_st_joint_positions = (uint32_t*) &(this->st_joint_positions);
      offset += 3;
      *val_st_joint_positions = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_joint_positions |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_joint_positions |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_joint_positions |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_joint_positions = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_joint_positions |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_joint_positions !=0)
        *val_st_joint_positions |= ((exp_st_joint_positions)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_joint_positions = -this->st_joint_positions;
>>>>>>> 114c33badc7e157f5d09deb42c0831bdbf295d3c
        memcpy( &(this->joint_positions[i]), &(this->st_joint_positions), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return SETMODELCONFIGURATION; };
    const char * getMD5(){ return "160eae60f51fabff255480c70afa289f"; };

  };

  class SetModelConfigurationResponse : public ros::Msg
  {
    public:
      bool success;
<<<<<<< HEAD
      const char* status_message;

    SetModelConfigurationResponse():
      success(0),
      status_message("")
    {
    }
=======
      char * status_message;
>>>>>>> 114c33badc7e157f5d09deb42c0831bdbf295d3c

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
<<<<<<< HEAD
      uint32_t length_status_message = strlen(this->status_message);
=======
      uint32_t length_status_message = strlen( (const char*) this->status_message);
>>>>>>> 114c33badc7e157f5d09deb42c0831bdbf295d3c
      memcpy(outbuffer + offset, &length_status_message, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->status_message, length_status_message);
      offset += length_status_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_status_message;
      memcpy(&length_status_message, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status_message-1]=0;
      this->status_message = (char *)(inbuffer + offset-1);
      offset += length_status_message;
     return offset;
    }

    const char * getType(){ return SETMODELCONFIGURATION; };
    const char * getMD5(){ return "2ec6f3eff0161f4257b808b12bc830c2"; };

  };

  class SetModelConfiguration {
    public:
    typedef SetModelConfigurationRequest Request;
    typedef SetModelConfigurationResponse Response;
  };

}
#endif
