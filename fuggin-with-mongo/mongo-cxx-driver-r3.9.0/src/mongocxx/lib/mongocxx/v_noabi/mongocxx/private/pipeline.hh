// Copyright 2014 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <bsoncxx/builder/basic/array.hpp>
#include <mongocxx/pipeline.hpp>

#include <mongocxx/config/private/prelude.hh>

namespace mongocxx {
inline namespace v_noabi {
class pipeline::impl {
   public:
    bsoncxx::builder::basic::array& sink() {
        return _builder;
    }

    bsoncxx::array::view view_array() {
        return _builder.view();
    }

    ///
    /// view() is deprecated. Use view_array() instead.
    ///
    bsoncxx::document::view view() {
        return _builder.view();
    }

   private:
    bsoncxx::builder::basic::array _builder;
};

}  // namespace v_noabi
}  // namespace mongocxx

#include <mongocxx/config/private/postlude.hh>
