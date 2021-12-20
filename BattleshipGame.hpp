#ifndef _BATTLESHIPGAME_HPP_
#define _BATTLESHIPGAME_HPP_

#include "IGame.hpp"

#include "IPlayer.hpp"

namespace mygame {

class BattleShipGame final : public IGame {
 public:
  BattleShipGame() = delete;
  BattleShipGame(std::shared_ptr<IPlayer> opponent);
  virtual ~BattleShipGame() = default;
  BattleShipGame(const BattleShipGame & ) = default;
  BattleShipGame( BattleShipGame && ) = default;
  BattleShipGame &operator=( const BattleShipGame & ) = default;
  BattleShipGame &operator=( BattleShipGame && ) = default;

  std::unique_ptr<IGame> clone() const override;

 protected:
 private:
};

}  // namespace mygame

#endif
