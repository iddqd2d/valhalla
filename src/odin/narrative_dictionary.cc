#include <boost/property_tree/ptree.hpp>

#include <valhalla/midgard/logging.h>

#include "odin/narrative_dictionary.h"

namespace {

// Read array as vector
template<typename T>
std::vector<T> as_vector(boost::property_tree::ptree const& pt,
                         boost::property_tree::ptree::key_type const& key) {
  std::vector<T> items;
  for (const auto& item : pt.get_child(key)) {
    items.push_back(item.second.get_value<T>());
  }
  return items;
}

}

namespace valhalla {
namespace odin {

NarrativeDictionary::NarrativeDictionary(
    const boost::property_tree::ptree& narrative_pt) {
  Load(narrative_pt);
}

void NarrativeDictionary::Load(
    const boost::property_tree::ptree& narrative_pt) {

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate start_subset...");
  // Populate start_subset
  Load(start_subset, narrative_pt.get_child(kStartKey));

  LOG_TRACE("Populate start_verbal_subset...");
  // Populate start_verbal_subset
  Load(start_verbal_subset, narrative_pt.get_child(kStartVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate destination_subset...");
  // Populate destination_subset
  Load(destination_subset, narrative_pt.get_child(kDestinationKey));

  LOG_TRACE("Populate destination_verbal_alert_subset...");
  // Populate destination_verbal_alert_subset
  Load(destination_verbal_alert_subset, narrative_pt.get_child(kDestinationVerbalAlertKey));

  LOG_TRACE("Populate destination_verbal_subset...");
  // Populate destination_verbal_subset
  Load(destination_verbal_subset, narrative_pt.get_child(kDestinationVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate continue_subset...");
  // Populate continue_subset
  Load(continue_subset, narrative_pt.get_child(kContinueKey));

  LOG_TRACE("Populate continue_verbal_alert_subset...");
  // Populate continue_verbal_alert_subset
  Load(continue_verbal_alert_subset, narrative_pt.get_child(kContinueVerbalAlertKey));

  LOG_TRACE("Populate continue_verbal_subset...");
  // Populate continue_verbal_subset
  Load(continue_verbal_subset, narrative_pt.get_child(kContinueVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate bear_subset...");
  // Populate bear_subset
  Load(bear_subset, narrative_pt.get_child(kBearKey));

  LOG_TRACE("Populate bear_verbal_subset...");
  // Populate bear_verbal_subset
  Load(bear_verbal_subset, narrative_pt.get_child(kBearVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate turn_subset...");
  // Populate turn_subset
  Load(turn_subset, narrative_pt.get_child(kTurnKey));

  LOG_TRACE("Populate turn_verbal_subset...");
  // Populate turn_verbal_subset
  Load(turn_verbal_subset, narrative_pt.get_child(kTurnVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate uturn_subset...");
  // Populate uturn_subset
  Load(uturn_subset, narrative_pt.get_child(kUturnKey));

  LOG_TRACE("Populate uturn_verbal_alert_subset...");
  // Populate uturn_verbal_alert_subset
  Load(uturn_verbal_alert_subset, narrative_pt.get_child(kUturnVerbalAlertKey));

  LOG_TRACE("Populate uturn_verbal_subset...");
  // Populate uturn_verbal_subset
  Load(uturn_verbal_subset, narrative_pt.get_child(kUturnVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate ramp_straight_subset...");
  // Populate ramp_straight_subset
  Load(ramp_straight_subset, narrative_pt.get_child(kRampStraightKey));

  LOG_TRACE("Populate ramp_straight_verbal_alert_subset...");
  // Populate ramp_straight_verbal_alert_subset
  Load(ramp_straight_verbal_alert_subset, narrative_pt.get_child(kRampStraightVerbalAlertKey));

  LOG_TRACE("Populate ramp_straight_verbal_subset...");
  // Populate ramp_straight_verbal_subset
  Load(ramp_straight_verbal_subset, narrative_pt.get_child(kRampStraightVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate ramp_subset...");
  // Populate ramp_subset
  Load(ramp_subset, narrative_pt.get_child(kRampKey));

  LOG_TRACE("Populate ramp_verbal_subset...");
  // Populate ramp_verbal_subset
  Load(ramp_verbal_subset, narrative_pt.get_child(kRampVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate exit_subset...");
  // Populate exit_subset
  Load(exit_subset, narrative_pt.get_child(kExitKey));

  LOG_TRACE("Populate exit_verbal_subset...");
  // Populate exit_verbal_subset
  Load(exit_verbal_subset, narrative_pt.get_child(kExitVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate keep_subset...");
  // Populate keep_subset
  Load(keep_subset, narrative_pt.get_child(kKeepKey));

  LOG_TRACE("Populate keep_verbal_subset...");
  // Populate keep_verbal_subset
  Load(keep_verbal_subset, narrative_pt.get_child(kKeepVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate keep_to_stay_on_subset...");
  // Populate keep_to_stay_on_subset
  Load(keep_to_stay_on_subset, narrative_pt.get_child(kKeepToStayOnKey));

  LOG_TRACE("Populate keep_to_stay_on_verbal_subset...");
  // Populate keep_to_stay_on_verbal_subset
  Load(keep_to_stay_on_verbal_subset, narrative_pt.get_child(kKeepToStayOnVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate merge_subset...");
  // Populate merge_subset
  Load(merge_subset, narrative_pt.get_child(kMergeKey));

  LOG_TRACE("Populate merge_verbal_subset...");
  // Populate merge_verbal_subset
  Load(merge_verbal_subset, narrative_pt.get_child(kMergeVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate enter_roundabout_subset...");
  // Populate enter_roundabout_subset
  Load(enter_roundabout_subset, narrative_pt.get_child(kEnterRoundaboutKey));

  LOG_TRACE("Populate enter_roundabout_verbal_subset...");
  // Populate enter_roundabout_verbal_subset
  Load(enter_roundabout_verbal_subset, narrative_pt.get_child(kEnterRoundaboutVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate exit_roundabout_subset...");
  // Populate exit_roundabout_subset
  Load(exit_roundabout_subset, narrative_pt.get_child(kExitRoundaboutKey));

  LOG_TRACE("Populate exit_roundabout_verbal_subset...");
  // Populate exit_roundabout_verbal_subset
  Load(exit_roundabout_verbal_subset, narrative_pt.get_child(kExitRoundaboutVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate enter_ferry_subset...");
  // Populate enter_ferry_subset
  Load(enter_ferry_subset, narrative_pt.get_child(kEnterFerryKey));

  LOG_TRACE("Populate enter_ferry_verbal_subset...");
  // Populate enter_ferry_verbal_subset
  Load(enter_ferry_verbal_subset, narrative_pt.get_child(kEnterFerryVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate exit_ferry_subset...");
  // Populate exit_ferry_subset
  Load(exit_ferry_subset, narrative_pt.get_child(kExitFerryKey));

  LOG_TRACE("Populate exit_ferry_verbal_subset...");
  // Populate exit_ferry_verbal_subset
  Load(exit_ferry_verbal_subset, narrative_pt.get_child(kExitFerryVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate transit_connection_start_subset...");
  // Populate transit_connection_start_subset
  Load(transit_connection_start_subset, narrative_pt.get_child(kTransitConnectionStartKey));

  LOG_TRACE("Populate transit_connection_start_verbal_subset...");
  // Populate transit_connection_start_verbal_subset
  Load(transit_connection_start_verbal_subset, narrative_pt.get_child(kTransitConnectionStartVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate post_transition_verbal_subset...");
  // Populate post_transition_verbal_subset
  Load(post_transition_verbal_subset, narrative_pt.get_child(kPostTransitionVerbalKey));

  /////////////////////////////////////////////////////////////////////////////
  LOG_TRACE("Populate verbal_multi_cue_subset...");
  // Populate verbal_multi_cue_subset
  Load(verbal_multi_cue_subset, narrative_pt.get_child(kVerbalMultiCueKey));

}

void NarrativeDictionary::Load(PhraseSet& phrase_handle,
                               const boost::property_tree::ptree& phrase_pt) {

  for (const auto& item : phrase_pt.get_child(kPhrasesKey)) {
    phrase_handle.phrases.emplace(item.first,
                                  item.second.get_value<std::string>());
  }
}

void NarrativeDictionary::Load(
    StartSubset& start_handle,
    const boost::property_tree::ptree& start_subset_pt) {

  // Populate phrases
  Load(static_cast<PhraseSet&>(start_handle), start_subset_pt);

  // Populate cardinal_directions
  start_handle.cardinal_directions = as_vector<std::string>(
      start_subset_pt, kCardinalDirectionsKey);

  // Populate empty_street_name_labels
  start_handle.empty_street_name_labels = as_vector<std::string>(
      start_subset_pt, kEmptyStreetNameLabelsKey);
}

void NarrativeDictionary::Load(
    StartVerbalSubset& start_verbal_handle,
    const boost::property_tree::ptree& start_verbal_subset_pt) {

  // Populate start_subset items
  Load(static_cast<StartSubset&>(start_verbal_handle), start_verbal_subset_pt);

  // Populate metric_lengths
  start_verbal_handle.metric_lengths = as_vector<std::string>(
      start_verbal_subset_pt, kMetricLengthsKey);

  // Populate us_customary_lengths
  start_verbal_handle.us_customary_lengths = as_vector<std::string>(
      start_verbal_subset_pt, kUsCustomaryLengthsKey);
}

void NarrativeDictionary::Load(
    DestinationSubset& destination_handle,
    const boost::property_tree::ptree& destination_subset_pt) {

  // Populate phrases
  Load(static_cast<PhraseSet&>(destination_handle), destination_subset_pt);

  // Populate relative_directions
  destination_handle.relative_directions = as_vector<std::string>(
      destination_subset_pt, kRelativeDirectionsKey);
}

void NarrativeDictionary::Load(
    ContinueSubset& continue_handle,
    const boost::property_tree::ptree& continue_subset_pt) {

  // Populate phrases
  Load(static_cast<PhraseSet&>(continue_handle), continue_subset_pt);

  // Populate empty_street_name_labels
  continue_handle.empty_street_name_labels = as_vector<std::string>(
      continue_subset_pt, kEmptyStreetNameLabelsKey);
}

void NarrativeDictionary::Load(
    ContinueVerbalSubset& continue_verbal_handle,
    const boost::property_tree::ptree& continue_verbal_subset_pt) {

  // Populate continue_subset items
  Load(static_cast<ContinueSubset&>(continue_verbal_handle), continue_verbal_subset_pt);

  // Populate metric_lengths
  continue_verbal_handle.metric_lengths = as_vector<std::string>(
      continue_verbal_subset_pt, kMetricLengthsKey);

  // Populate us_customary_lengths
  continue_verbal_handle.us_customary_lengths = as_vector<std::string>(
      continue_verbal_subset_pt, kUsCustomaryLengthsKey);
}

void NarrativeDictionary::Load(
    TurnSubset& turn_handle,
    const boost::property_tree::ptree& turn_subset_pt) {

  // Populate phrases
  Load(static_cast<PhraseSet&>(turn_handle), turn_subset_pt);

  // Populate relative_directions
  turn_handle.relative_directions = as_vector<std::string>(
      turn_subset_pt, kRelativeDirectionsKey);

  // Populate empty_street_name_labels
  turn_handle.empty_street_name_labels = as_vector<std::string>(
      turn_subset_pt, kEmptyStreetNameLabelsKey);
}

void NarrativeDictionary::Load(
    RampSubset& ramp_handle,
    const boost::property_tree::ptree& ramp_subset_pt) {

  // Populate phrases
  Load(static_cast<PhraseSet&>(ramp_handle), ramp_subset_pt);

  // Populate relative_directions
  ramp_handle.relative_directions = as_vector<std::string>(
      ramp_subset_pt, kRelativeDirectionsKey);

}

void NarrativeDictionary::Load(
    KeepSubset& keep_handle,
    const boost::property_tree::ptree& keep_subset_pt) {

  // Populate ramp_subset items
  Load(static_cast<RampSubset&>(keep_handle), keep_subset_pt);

  // Populate empty_street_name_labels
  keep_handle.empty_street_name_labels = as_vector<std::string>(
      keep_subset_pt, kEmptyStreetNameLabelsKey);

}

void NarrativeDictionary::Load(
    EnterRoundaboutSubset& enter_roundabout_handle,
    const boost::property_tree::ptree& enter_roundabout_subset_pt) {

  // Populate phrases
  Load(static_cast<PhraseSet&>(enter_roundabout_handle), enter_roundabout_subset_pt);

  // Populate ordinal_values
  enter_roundabout_handle.ordinal_values = as_vector<std::string>(
      enter_roundabout_subset_pt, kOrdinalValuesKey);

}

void NarrativeDictionary::Load(
    EnterFerrySubset& enter_ferry_handle,
    const boost::property_tree::ptree& enter_ferry_subset_pt) {

  // Populate phrases
  Load(static_cast<PhraseSet&>(enter_ferry_handle), enter_ferry_subset_pt);

  // Populate empty_street_name_labels
  enter_ferry_handle.empty_street_name_labels = as_vector<std::string>(
      enter_ferry_subset_pt, kEmptyStreetNameLabelsKey);

  // Populate ferry_label
  enter_ferry_handle.ferry_label = enter_ferry_subset_pt.get<std::string>(
      kFerryLabelKey);

}

void NarrativeDictionary::Load(
    PostTransitionVerbalSubset& post_transition_verbal_handle,
    const boost::property_tree::ptree& post_transition_verbal_subset_pt) {

  // Populate phrases
  Load(static_cast<PhraseSet&>(post_transition_verbal_handle),
       post_transition_verbal_subset_pt);

  // Populate metric_lengths
  post_transition_verbal_handle.metric_lengths = as_vector<std::string>(
      post_transition_verbal_subset_pt, kMetricLengthsKey);

  // Populate us_customary_lengths
  post_transition_verbal_handle.us_customary_lengths = as_vector<std::string>(
      post_transition_verbal_subset_pt, kUsCustomaryLengthsKey);

  // Populate empty_street_name_labels
  post_transition_verbal_handle.empty_street_name_labels = as_vector<std::string>(
      post_transition_verbal_subset_pt, kEmptyStreetNameLabelsKey);
}

}
}
