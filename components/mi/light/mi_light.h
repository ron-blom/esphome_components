#pragma once

#include "esphome/core/component.h"
#include "esphome/components/mi/mi.h"
#include "esphome/components/light/light_output.h"

namespace esphome {
  namespace mi {

  class MiLight : public Component, public light::LightOutput {
   public:

    MiLight();
    ~MiLight();

    void set_bulb_id(uint16_t deviceId, uint8_t groupId, String remoteType);

    void setup() override;
    void dump_config() override;

    void set_mi_parent(Mi *parent) { this->parent_ = parent; }

    light::LightTraits get_traits() override;
    void setup_state(light::LightState *state) override;
    void write_state(light::LightState *state) override;

   private:

    BulbId bulbId = {0, 0, REMOTE_TYPE_RGB_CCT};
    Mi *parent_;
    light::LightState *state_{nullptr};
  };

  }  // namespace mi
}  // namespace esphome
