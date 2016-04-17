// Copyright 2015 Google Inc. All Rights Reserved.
// Author: Sebastian Schaffert <schaffert@google.com>

#ifndef HAVE_SERIALIZERJSON_H_
#define HAVE_SERIALIZERJSON_H_

#include <iostream>
#include <util/json/json.h>

namespace wikidata {
namespace primarysources {
namespace model {
class Statement;
}

namespace serializer {

    /**
    * Add a statement to the Wikidata JSON representation passed as output
    * parameter. Uses the WikiData JSON format documented at
    * https://www.mediawiki.org/wiki/Wikibase/Notes/JSON .
    * Each statement is represented as a "claim" in the Wikidata terminology.
    */
    void writeStatementWikidataJSON(
            const model::Statement& stmt, Json::Value* result);


    /**
    * Write a collection of statements to an output stream as JSON.
    * Uses the WikiData JSON format documented at
    * https://www.mediawiki.org/wiki/Wikibase/Notes/JSON .
    * Each statement is represented as a "claim" in the Wikidata terminology.
    */
    template<typename Iterator>
    void writeWikidataJSON(Iterator begin, Iterator end, std::ostream* out) {
        Json::Value entities;

        for (; begin != end; ++begin) {
            writeStatementWikidataJSON(*begin, &entities);
        }

        Json::Value result;
        result["entities"] = entities;
        *out << result;
    }

}  // namespace serializer
}  // namespace primarysources
}  // namespace wikidata
#endif  // HAVE_SERIALIZERJSON_H_
