#pragma once

#ifdef ANDROID
#include <fbjni/fbjni.h>
#endif
#include <react/debug/react_native_assert.h>
#include <react/renderer/components/rnscreens/Props.h>
#include <react/renderer/components/rnscreens/utils/RectUtil.h>
#include <react/renderer/core/ConcreteComponentDescriptor.h>
#include "RNSScreenStackHeaderConfigShadowNode.h"

namespace facebook::react {

using namespace rnscreens;

class RNSScreenStackHeaderConfigComponentDescriptor final
    : public ConcreteComponentDescriptor<RNSScreenStackHeaderConfigShadowNode> {
 public:
  using ConcreteComponentDescriptor::ConcreteComponentDescriptor;

  void adopt(ShadowNode &shadowNode) const override {
    react_native_assert(
        dynamic_cast<RNSScreenStackHeaderConfigShadowNode *>(&shadowNode));
    auto &configShadowNode =
        static_cast<RNSScreenStackHeaderConfigShadowNode &>(shadowNode);

    react_native_assert(
        dynamic_cast<YogaLayoutableShadowNode *>(&configShadowNode));
    auto &layoutableShadowNode =
        dynamic_cast<YogaLayoutableShadowNode &>(configShadowNode);

    auto state = std::static_pointer_cast<
        const RNSScreenStackHeaderConfigShadowNode::ConcreteState>(
        shadowNode.getState());
    auto stateData = state->getData();

    if (stateData.frameSize.width != 0 && stateData.frameSize.height != 0) {
        layoutableShadowNode.setSize(Size{stateData.frameSize.width, stateData.frameSize.height});
    }

    ConcreteComponentDescriptor::adopt(shadowNode);
  }
};

} // namespace facebook::react
