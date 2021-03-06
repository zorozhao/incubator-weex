/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
#ifndef WEEX_PROJECT_RENDERCREATOR_H
#define WEEX_PROJECT_RENDERCREATOR_H

#include <string>

namespace WeexCore {

  class IRenderObject;

  class RenderCreator {

  private:
    RenderCreator() {}

    ~RenderCreator() {}

    //just to release singleton object
    class Garbo {
    public:
      ~Garbo() {
        if (RenderCreator::m_pInstance) {
          delete RenderCreator::m_pInstance;
        }
      }
    };

    static Garbo garbo;

  public:

    static RenderCreator *GetInstance() {
      if (!m_pInstance) {
        m_pInstance = new RenderCreator();
      }
      return m_pInstance;
    }

    IRenderObject *CreateRender(const std::string &type, const std::string &ref);

  private:
    static RenderCreator *m_pInstance;
  };
}

#endif //WEEX_PROJECT_RENDERCREATOR_H
