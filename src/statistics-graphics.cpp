#include "statistics-graphics.hpp"
#include "color.hpp"
#include <array>
#include <iomanip>
#include <sstream>

namespace Statistics {

std::string TotalStatisticsOverlay(total_stats_display_data_t tsdd) {
  constexpr auto stats_title_text = "STATISTICS";
  constexpr auto divider_text = "──────────";
  constexpr auto header_border_text = "┌────────────────────┬─────────────┐";
  constexpr auto footer_border_text = "└────────────────────┴─────────────┘";
  const auto stats_attributes_text = {"Best Score", "Game Count",
                                      "Number of Wins", "Total Moves Played",
                                      "Total Duration"};
  constexpr auto no_save_text = "No saved statistics.";
  constexpr auto any_key_exit_text =
      "Press any key to return to the main menu... ";
  constexpr auto sp = "  ";

  enum TotalStatsDisplayDataFields {
    IDX_DATA_AVAILABLE,
    IDX_BEST_SCORE,
    IDX_GAME_COUNT,
    IDX_GAME_WIN_COUNT,
    IDX_TOTAL_MOVE_COUNT,
    IDX_TOTAL_DURATION,
    MAX_TOTALSTATSDISPLAYDATA_INDEXES
  };

  std::ostringstream stats_richtext;

  const auto stats_file_loaded = std::get<IDX_DATA_AVAILABLE>(tsdd);
  if (stats_file_loaded) {
    constexpr auto num_of_stats_attributes_text = 5;
    auto data_stats = std::array<std::string, num_of_stats_attributes_text>{};
    data_stats = {std::get<IDX_BEST_SCORE>(tsdd),
                  std::get<IDX_GAME_COUNT>(tsdd),
                  std::get<IDX_GAME_WIN_COUNT>(tsdd),
                  std::get<IDX_TOTAL_MOVE_COUNT>(tsdd),
                  std::get<IDX_TOTAL_DURATION>(tsdd)};

    auto counter{0};
    const auto populate_stats_info = [data_stats, stats_attributes_text,
                                      &counter,
                                      &stats_richtext](const std::string) {
      stats_richtext << sp << "│ " << bold_on << std::left << std::setw(18)
                     << std::begin(stats_attributes_text)[counter] << bold_off
                     << " │ " << std::right << std::setw(11)
                     << data_stats[counter] << " │"
                     << "\n";
      counter++;
    };

    stats_richtext << green << bold_on << sp << stats_title_text << bold_off
                   << def << "\n";
    stats_richtext << green << bold_on << sp << divider_text << bold_off << def
                   << "\n";
    stats_richtext << sp << header_border_text << "\n";

    for (const auto s : stats_attributes_text) {
      populate_stats_info(s);
    }
    stats_richtext << sp << footer_border_text << "\n";

  } else {
    stats_richtext << sp << no_save_text << "\n";
  }

  stats_richtext << "\n\n\n";
  stats_richtext << sp << any_key_exit_text;

  return stats_richtext.str();
}

} // namespace Statistics
