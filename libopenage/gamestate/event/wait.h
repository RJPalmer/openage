// Copyright 2023-2023 the openage authors. See copying.md for legal info.

#pragma once

#include "event/evententity.h"
#include "event/eventhandler.h"

namespace openage {

namespace event {
class EventLoop;
class Event;
class EventEntity;
class State;
} // namespace event

namespace gamestate::event {

/**
 * Waits until the event is handled and calls back the entity manager.
 */
class WaitHandler : public openage::event::OnceEventHandler {
public:
	WaitHandler();
	~WaitHandler() = default;

	void setup_event(const std::shared_ptr<openage::event::Event> &event,
	                 const std::shared_ptr<openage::event::State> &state) override;

	void invoke(openage::event::EventLoop &loop,
	            const std::shared_ptr<openage::event::EventEntity> &target,
	            const std::shared_ptr<openage::event::State> &state,
	            const curve::time_t &time,
	            const param_map &params) override;

	curve::time_t predict_invoke_time(const std::shared_ptr<openage::event::EventEntity> &target,
	                                  const std::shared_ptr<openage::event::State> &state,
	                                  const curve::time_t &at) override;
};
} // namespace gamestate::event
} // namespace openage
